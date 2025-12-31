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

int board[51][51];
int board2[51][51];
int vis[51][51];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, g, r;
    vector<pair<int, int>> cand;
    cin >> n >> m >> g >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) cand.push_back({ i, j });
        }
    }

    vector<int> v;
    for (int i = 0; i < cand.size() - g - r; i++) v.push_back(0);
    for (int i = 0; i < g; i++) v.push_back(1);
    for (int i = 0; i < r; i++) v.push_back(2);
    int ans = 0;
    do {
        int flower = 0;
        for (int i = 0; i < 51; i++)
            fill(vis[i], vis[i] + 51, -1);

        for (int i = 0; i < 51; i++) {
            for (int j = 0; j < 51; j++) {
                board2[i][j] = board[i][j];
            }
        }
        queue<pair<int, int>> q;
        for (int i = 0; i < v.size(); i++) {
            int x = cand[i].X, y = cand[i].Y;
            if (v[i] == 1) {
                vis[x][y] = 0;
                q.push({ x, y });
                board2[x][y] = -1;
            }
            else if (v[i] == 2) {
                vis[x][y] = 0;
                q.push({ x, y });
                board2[x][y] = -2;
            }
        }

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (board2[cur.X][cur.Y] == 3) continue;
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (board2[nx][ny] == 0 || board2[nx][ny] == 3) continue;
                if (vis[nx][ny] == -1) {
                    vis[nx][ny] = vis[cur.X][cur.Y] + 1;
                    board2[nx][ny] = board2[cur.X][cur.Y];
                    q.push({ nx, ny });
                }
                else if (vis[cur.X][cur.Y] + 1 == vis[nx][ny] && (-3 - board2[cur.X][cur.Y]) == board2[nx][ny]) {
                    board2[nx][ny] = 3;
                    flower++;
                }
            }
        }
        //    cout << "board2: \n";
        //    for (int i = 0; i < n; i++) {
        //        for (int j = 0; j < m; j++) {
        //            cout << board2[i][j] << " ";
        //        }
        //        cout << "\n";
        //    }
        //cout << "\n";
        //for (int i = 0; i < n; i++) {
        //    for (int j = 0; j < m; j++) {
        //        cout << vis[i][j] << " ";
        //    }
        //    cout << "\n";
        //}
        ans = max(ans, flower);

    } while (next_permutation(v.begin(), v.end()));
    //cout << "\n";
    //for (int i = 0; i < n; i++) {
    //    for (int j = 0; j < m; j++) {
    //        cout << board2[i][j] << " ";
    //    }
    //cout << "\n";
    //}
    //cout << "\n";
    //    for (int i = 0; i < n; i++) {
    //        for (int j = 0; j < m; j++) {
    //            cout << vis[i][j] << " ";
    //        }
    //        cout << "\n";
    //    }
    cout << ans;
}
