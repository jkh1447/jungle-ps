#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int dist[101][101];

int solution(vector<string> maps) {
    int answer = 0;
    
    int lx, ly;
    int sx, sy;
    int ex, ey;
    
    int N = maps.size(), M = maps[0].size();
    
    for(int i=0; i<101; i++)
        for(int j=0; j<101; j++){
            dist[i][j] = -1;
        }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if (maps[i][j] == 'S') {
                sx = i; sy = j;
            }
            if (maps[i][j] == 'L') {
                lx = i; ly = j;
            }
            if (maps[i][j] == 'E') {
                ex = i; ey = j;
            }
        }
    }
    // cout << sx << sy << lx << ly << ex << ey << "\n";
    
    dist[sx][sy] = 0;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        
        if (cur.first == lx && cur.second == ly) {
            break;
        }
        
        for(int dir=0; dir<4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (maps[nx][ny] == 'X' || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
    
    int hap = dist[lx][ly];
    if (dist[lx][ly] == -1) {
        answer = -1;
        return answer;
    }
    
    for(int i=0; i<101; i++)
        for(int j=0; j<101; j++){
            dist[i][j] = -1;
        }
    queue<pair<int, int>> q2;
    dist[lx][ly] = 0;
    q2.push({lx, ly});
    
    while(!q2.empty()) {
        auto cur = q2.front(); q2.pop();
        
        if (cur.first == ex && cur.second == ey) {
            break;
        }
        
        for(int dir=0; dir<4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (maps[nx][ny] == 'X' || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q2.push({nx, ny});
        }
    }
    if (dist[ex][ey] == -1) {
        answer = -1;
    }
    else {
        answer = hap + dist[ex][ey];
    }

    
    return answer;
}