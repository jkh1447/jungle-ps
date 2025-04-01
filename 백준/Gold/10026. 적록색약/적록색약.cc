#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
string board[102];
int vis[102][102];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    queue<pair<int, int>> q;
    int ans1 = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (vis[i][j] == 0) {
                ans1++;
                q.push({ i, j });

                while (!q.empty()) {
                    pair<int, int> cur = q.front(); q.pop();
                    //cout << cur.X << ", " << cur.Y << "-> ";
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        
                        if (vis[nx][ny] || board[nx][ny] != board[cur.X][cur.Y]) continue;
                        vis[nx][ny] = 1;
                        q.push({ nx, ny });
                    }
                }
                //cout << "end\n";
            }
        }
    }

    for (int i = 0; i < n; i++) {
        fill(vis[i], vis[i] + n, 0);
    }

    int ans2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (vis[i][j] == 0) {
                ans2++;
                q.push({ i, j });

                while (!q.empty()) {
                    pair<int, int> cur = q.front(); q.pop();
                    //cout << cur.X << ", " << cur.Y << "-> ";
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (board[cur.X][cur.Y] == 'R' || board[cur.X][cur.Y] == 'G') {
                            if (board[nx][ny] == 'R' || board[nx][ny] == 'G') {
                                if (vis[nx][ny] == 0) {

                                    
                                    vis[nx][ny] = 1;
                                    q.push({ nx, ny });
                                    continue;
                                }
                            }
                        }
                        if (vis[nx][ny] || board[nx][ny] != board[cur.X][cur.Y]) continue;
                        vis[nx][ny] = 1;
                        q.push({ nx, ny });
                    }
                }
                //cout << "end\n";
            }
        }
    }

    cout << ans1<<" "<<ans2;
    
}