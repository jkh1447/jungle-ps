#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int dist[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int solution(vector<string> board) {
    int answer = 0;
    for(int i=0; i<101; i++)
        fill(dist[i], dist[i]+101, -1);
    int N = board.size(), M = board[0].size();
    int sx, sy;
    int ex, ey;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if (board[i][j] == 'R') {
                sx = i;
                sy = j;
            }
            if (board[i][j] == 'G') {
                ex = i;
                ey = j;
            }
        }
    }
    
    queue<pair<int, int>> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;
    
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        
        for(int dir=0; dir<4; dir++){
            int nx = cur.first;
            int ny = cur.second;
            while(true){
                nx += dx[dir];
                ny += dy[dir];
                if (nx < 0 || nx >=N || ny < 0 || ny >= M) {
                    nx -= dx[dir];
                    ny -= dy[dir];
                    break;
                }
                if (board[nx][ny] == 'D') {
                    nx -= dx[dir];
                    ny -= dy[dir];
                    break;
                }
            }
            if (dist[nx][ny] != -1 || (nx == cur.first & ny == cur.second)) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
                
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    answer = dist[ex][ey];
    return answer;
}