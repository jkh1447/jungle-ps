#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

int dx[4] = { 1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


//int dx2[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy2[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int board[1001][1001];
int s_dist[1001][1001];
int f_dist[1001][1001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, t;
    cin >> t;

    for (int tc = 0; tc < t; tc++) {


        cin >> m >> n;

        for (int i = 0; i < n; i++) {
            fill(s_dist[i], s_dist[i] + m, -1);
            fill(f_dist[i], f_dist[i] + m, -1);
        }
            
        string str;
        queue<pair<int, int>> fq;
        queue<pair<int, int>> sq;

        for (int i = 0; i < n; i++) {
            cin >> str;
            for (int j = 0; j < m; j++) {
                board[i][j] = str[j];
                if (board[i][j] == '*') {
                    f_dist[i][j] = 0;
                    fq.push({ i, j });
                }
                else if (board[i][j] == '@') {
                    s_dist[i][j] = 0;
                    sq.push({ i, j });
                }
            }
        }

        while (!fq.empty()) {
            auto cur = fq.front();
            fq.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (board[nx][ny] == '#' || f_dist[nx][ny] >= 0) continue;
                f_dist[nx][ny] = f_dist[cur.X][cur.Y] + 1;
                fq.push({ nx, ny });
            }
        }
        bool flag = false;
        while (!sq.empty()) {
            auto cur = sq.front();
            sq.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    cout << s_dist[cur.X][cur.Y] + 1<<"\n";
                    flag = true;
                    break;
                }
                if (board[nx][ny] == '#' || s_dist[nx][ny] >= 0) continue;
                if (f_dist[nx][ny] == -1 || s_dist[cur.X][cur.Y] + 1 < f_dist[nx][ny]) {

                    s_dist[nx][ny] = s_dist[cur.X][cur.Y] + 1;
                    sq.push({ nx, ny });
                }

                    
                
                
            }

            if (flag) break;
        }
        if(!flag)
            cout << "IMPOSSIBLE\n";
    }


}