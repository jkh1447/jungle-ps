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

int board[10][10];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    vector<pair<int, int>> c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            c.push_back({ i, j });
        }
    }

    int ans = 0;
    for (int i = 0; i < c.size()-2; i++) {
        if (board[c[i].X][c[i].Y] != 0) continue;
        for (int j = i + 1; j < c.size()-1; j++) {
            if (board[c[j].X][c[j].Y] != 0) continue;
            for (int k = j + 1; k < c.size(); k++) {
                if (board[c[k].X][c[k].Y] != 0) continue;
                int board2[10][10];
                for (int l = 0; l < n; l++)
                    for (int o = 0; o < m; o++)
                        board2[l][o] = board[l][o];
                

                int x1 = c[i].X, y1 = c[i].Y;
                int x2 = c[j].X, y2 = c[j].Y;
                int x3 = c[k].X, y3 = c[k].Y;

                board2[x1][y1] = 1;
                board2[x2][y2] = 1;
                board2[x3][y3] = 1;

                queue<pair<int, int>> q;
                vector<vector<int>> vis(n, vector<int>(m));
                for (int l = 0; l < n; l++) {
                    for (int o = 0; o < m; o++) {
                        if (board2[l][o] == 1 || board2[l][o] == 0) continue;
                        vis[l][o] = 1;
                        q.push({ l, o });

                        while (!q.empty()) {
                            auto cur = q.front(); q.pop();
                            for (int dir = 0; dir < 4; dir++) {
                                int nx = cur.X + dx[dir];
                                int ny = cur.Y + dy[dir];

                                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                                if (board2[nx][ny] == 1 || vis[nx][ny]) continue;
                                board2[nx][ny] = 2;
                                vis[nx][ny] = 1;
                                q.push({ nx, ny });
                            }
                        }

                    }
                }
                int cnt = 0;
                for (int l = 0; l < n; l++) {
                    for (int o = 0; o < m; o++) {
                        if (board2[l][o] == 0) cnt++;
                    }
                }
                ans = max(cnt, ans);
            }
        }
    }

    cout << ans;
}