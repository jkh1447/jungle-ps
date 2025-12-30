#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stack>
#include <deque>
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define LL long long

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };
int board[21][21];
int n;
vector<int> cnt(vector<int> &s, int x, int y) {
    vector<int> res(2, 0);
    
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
        if (board[nx][ny] == 0) {
            res[1]++;
            continue;
        }
        bool flag = false;
        for (int i = 1; i < 5; i++) {
            if (board[nx][ny] == s[i]) {
                res[0]++;
                break;
            }
        }

    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

   
    cin >> n;
    vector<vector<int>> v(n*n);
    for (int i = 0; i < n * n; i++) {
        for (int j = 0; j < 5; j++) {
            int s;
            cin >> s;
            v[i].push_back(s);
        }
    }


    for (auto s : v) {
        int stu = s[0];
        int maxCnt = 0;
        int minEmptyCnt = -1;
        int maxI, maxJ;
        bool flag = false;
        int noI, noJ;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (board[i][j] == 0) {
                    noI = i; noJ = j;
                    vector<int> tmp = cnt(s, i, j);
                    int count = tmp[0];
                    int emptyCount = tmp[1];
                    // cout << "count, emptyCount: " << count << " " << emptyCount << "\n";
                    if (maxCnt < count) {
                        maxCnt = count;
                        minEmptyCnt = emptyCount;
                        maxI = i;
                        maxJ = j;
                        flag = true;
                    }
                    else if (maxCnt == count) {
                        if (minEmptyCnt < emptyCount) {
                            maxCnt = count;
                            minEmptyCnt = emptyCount;
                            maxI = i;
                            maxJ = j;
                            flag = true;
                        }
                        else if (minEmptyCnt == emptyCount && i < maxI) {
                            maxCnt = count;
                            minEmptyCnt = emptyCount;
                            maxI = i;
                            maxJ = j;
                            flag = true;
                        }
                        else if (minEmptyCnt == emptyCount && j < maxJ) {
                            maxCnt = count;
                            minEmptyCnt = emptyCount;
                            maxI = i;
                            maxJ = j;
                            flag = true;
                        }
                        
                    }

                   
                }
            }
        }
        if (!flag) {
            maxI = noI;
            maxJ = noJ;
        }

        // cout << "maxI, maxJ: " << maxI << " " << maxJ << "\n";
        board[maxI][maxJ] = stu;

        
    }


    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int cur = board[i][j];
            for (auto s : v) {
                if (s[0] == cur) {
                    vector<int> tmp = cnt(s, i, j);
                    int e = tmp[0];
                    if (e != 0) {
                        e--;
                        int score = 1;
                        while (e--) {
                            score *= 10;
                        }
                        ans += score;
                        break;
                    }
                }
            }
        }
        
    }

    cout << ans;
}
