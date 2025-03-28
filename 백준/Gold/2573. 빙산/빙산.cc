#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

int dx[4] = { 1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


//int dx2[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy2[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int board[301][301];
int dist[301][301];




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

    queue<pair<int, int>> q;
    

    
    int ans = 0;
    while (true) {
        for(int i=0; i<n; i++)
            fill(dist[i], dist[i] + m, 0);

        int sub[301][301] = {};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] != 0) {
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];

                        if (board[nx][ny] == 0) sub[i][j]++;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] != 0) {
                    board[i][j] -= sub[i][j];
                    if (board[i][j] < 0) board[i][j] = 0;
                }
            }
        }
        //cout << "\n";
        //for (int i = 0; i < n; i++) {
        //    for (int j = 0; j < m; j++) {
        //        cout << board[i][j] << " ";
        //    }
        //    cout << "\n";
        //}
        //cout << "\n";

        ans++;
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] > 0 && dist[i][j] == 0) {
                    count++;
                    dist[i][j] = 1;
                    q.push({ i, j });

                    while (!q.empty()) {
                        auto cur = q.front();
                        q.pop();
                        //cout << cur.X << ", " << cur.Y << "-> ";
                        for (int dir = 0; dir < 4; dir++) {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];

                            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                            if (dist[nx][ny] > 0 || board[nx][ny] == 0) continue;
                            dist[nx][ny] = 1;
                            q.push({ nx, ny });
                        }
                    }
                }


            }
        }
        //cout << "count: " << count << "\n";
        if (count >= 2) {
            cout << ans;
            return 0;
        }
        else if (count == 0) {
            cout << 0;
            return 0;
        }
    }

    cout << 0;
}