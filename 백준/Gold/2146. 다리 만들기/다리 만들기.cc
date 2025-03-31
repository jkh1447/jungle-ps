#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = {0, 1, 0, -1};
int n, m;
int board[102][102];
int vis[102][102];
int con[102][102];


void printVis() {
    cout << "vis: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << vis[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
      
}
void printCon() {
    cout << "con: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << con[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

}


bool isOut(int i, int j) {
    for (int dir = 0; dir < 4; dir++) {
        int nx = i + dx[dir];
        int ny = j + dy[dir];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (board[nx][ny] != 1) return true;
    }
    return false;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);



    cin >> n;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];


    //대륙 넘버링 (1, 2, 3...)
    int num = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1 && vis[i][j] == 0) {
                queue<pair<int, int>> q;
                q.push({ i, j });
                vis[i][j] = 1;
                con[i][j] = num;
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (board[nx][ny] == 0 || vis[nx][ny] > 0) continue;
                        vis[nx][ny] = vis[cur.X][cur.Y] + 1;
                        con[nx][ny] = num;
                        q.push({ nx, ny });
                    }

                }

                num++;
            }
        }
    }

 
    
    for (int i = 0; i < n; i++) {
        fill(vis[i], vis[i] + n, 0);
    }
    int ans = 100000;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1 && isOut(i, j)) {
                for (int i = 0; i < n; i++) {
                    fill(vis[i], vis[i] + n, 0);
                }
                //cout << i << ", " << j << " -> ";
                queue<pair<int, int>> q;
                q.push({ i, j });
                vis[i][j] = 1;

                while (!q.empty()) {
                    auto cur = q.front(); 
                    q.pop();
                    
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (board[nx][ny] == 1 && con[i][j] != con[nx][ny]) {
                            //cout << nx << ", " << ny << "\n";
                            if (vis[cur.X][cur.Y] < ans) ans = vis[cur.X][cur.Y];
                            continue;
                        }
                        if (board[nx][ny] == 1 || vis[nx][ny] > 0) continue; //자기 대륙이거나 방문한곳이면 continue;
                        vis[nx][ny] = vis[cur.X][cur.Y] + 1;
                        q.push({ nx, ny });
                    }
                    
                }
                //printVis();
                //cout << "ans: " << ans-1 << "\n";
            }
        }
    }

    cout << ans - 1;

}