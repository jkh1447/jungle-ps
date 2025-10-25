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

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };

int board1[502][502];
int board2[502][502];
int N, M, B;
int flat(int h, int b) {
    int t = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) board2[i][j] = board1[i][j];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board2[i][j] > h) {
                int tmp = board2[i][j] - h;
                b += tmp;
                board2[i][j] = h;
                t += 2 * tmp;
            }
        }
    }
    bool flag = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board2[i][j] < h) {
                int tmp = h - board2[i][j];
                if (tmp <= b) {
                    board2[i][j] = h;
                    t += tmp;
                    b -= tmp;
                }
                else {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) break;
    }

    if (flag) return -1;
    else return t;

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> B;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board1[i][j];
        }
    }

    
    vector<pair<int, int>> ans;
    for (int i = 0; i <= 256; i++) {
        int tmp = flat(i, B);
        if (tmp != -1) {
            ans.push_back({ tmp, i });
        }
        
    }
    sort(ans.begin(), ans.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.X == b.X) return a.Y > b.Y;
        return a.X < b.X;
        });

    cout << ans[0].X << " " << ans[0].Y;



}