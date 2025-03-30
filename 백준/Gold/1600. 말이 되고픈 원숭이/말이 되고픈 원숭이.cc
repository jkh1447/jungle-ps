#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

int dx1[4] = { 1, 0, -1, 0 };
int dy1[4] = {0, 1, 0, -1};

int dx2[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy2[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int n, m, k;
int board[202][202];

int dist[202][202][32];

void printDist() {
    cout << "\n";
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < m; l++) {
                cout << dist[j][l][i] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);


    
    cin >> k;

    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    queue<tuple<int, int, int>> q;
    q.push({ 0, 0, 0 });
    dist[0][0][0] = 1;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = get<0>(cur) + dx1[dir];
            int ny = get<1>(cur) + dy1[dir];
            int nz = get<2>(cur);
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny][nz] > 0 || board[nx][ny] == 1) continue;
            dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            q.push({ nx, ny, nz });
        }

        if (get<2>(cur) < k) {
            for (int dir = 0; dir < 8; dir++) {
                int nx = get<0>(cur) + dx2[dir];
                int ny = get<1>(cur) + dy2[dir];
                int nz = get<2>(cur) + 1;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (dist[nx][ny][nz] > 0 || board[nx][ny] == 1)continue;
                dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
                q.push({ nx, ny, nz });
            }
        }
    }

    //printDist();

    int min = 100000;
    for (int i = 0; i <= k; i++) {
        if (dist[n - 1][m - 1][i] != 0 && min > dist[n - 1][m - 1][i]) {
            min = dist[n - 1][m - 1][i];
        }
    }

    if (min == 100000) cout << -1;
    else cout << min - 1;
}