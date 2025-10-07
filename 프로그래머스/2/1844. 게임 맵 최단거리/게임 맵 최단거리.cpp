#include<vector>
#include<bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dist[102][102];
int solution(vector<vector<int> > maps)
{
    
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    for(int i=0; i<n; i++)
        fill(dist[i], dist[i] + m, -1);
    dist[0][0] = 1;
    queue<pair<int, int>> q; q.push({0, 0});
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] > 0 || maps[nx][ny] == 0) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
    answer = dist[n-1][m-1];
    return answer;
}