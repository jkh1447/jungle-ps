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

// 아래, 오른쪽, 위, 왼쪽
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

//int dx[4] = { -1, 0, 1, 0 };
//int dy[4] = { 0, 1, 0, -1 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };

//int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
//int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

using namespace std;

int board[101][101];
int vis[101][101];
int N, M, K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N >> K;
    while (K--) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;

        for (int i = sx; i < ex; i++) {
            for (int j = sy; j < ey; j++) {
                board[i][j] = 1;
            }
        }
    }

    vector<int> ans;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (vis[i][j] || board[i][j] != 0) continue;
            int cnt = 0;
            vis[i][j] = 1;
            queue<pair<int, int>> q;
            q.push({ i, j });
            while (!q.empty()) {
                auto cur = q.front(); q.pop();
                cnt++;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                    if (vis[nx][ny] || board[nx][ny] != 0) continue;
                    vis[nx][ny] = 1;
                    q.push({ nx, ny });
                }
            }

            ans.push_back(cnt);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int cur : ans) cout << cur << " ";
}

