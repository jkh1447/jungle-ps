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

int n, m, k;
char board[102][102];
bool vis[102][102];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        fill(board[i], board[i] + m, '.');
    }
    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        board[r-1][c-1] = '#';
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] || board[i][j] == '.') continue;
            int cnt = 0;
            queue<pair<int, int>> q;
            q.push({ i, j });
            vis[i][j] = true;

            while (!q.empty()) {
                auto cur = q.front();
                cnt++;
                q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (vis[nx][ny] || board[nx][ny] == '.') continue;
                    vis[nx][ny] = true;
                    q.push({ nx, ny });
                }
            }

            ans = max(ans, cnt);
        }
    }

    cout << ans;
}