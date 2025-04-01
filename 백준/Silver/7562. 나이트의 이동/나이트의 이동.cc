#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1};

int board[302][302];
int dist[302][302];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++) {

        int I, i, j, di, dj;
        queue<pair<int, int>> q;

        cin >> I;

        for (int i = 0; i < I; i++) {
            fill(dist[i], dist[i] + I, -1);
        }

        cin >> i >> j;

        board[i][j] = 1;
        dist[i][j] = 0;
        q.push({ i, j });
        cin >> di >> dj;

        while (!q.empty()) {
            pair<int, int> cur = q.front(); q.pop();
            if (cur.X == di && cur.Y == dj) {
                cout << dist[cur.X][cur.Y] << "\n";
                break;
            }
            for (int i = 0; i < 8; i++) {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];

                if (nx < 0 || nx >= I || ny < 0 || ny >= I) continue;
                if (dist[nx][ny] >= 0) continue;

                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                q.push({ nx, ny });

            }
        }

    }
    
}