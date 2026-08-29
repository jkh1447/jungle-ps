#include<vector>
#include<bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dist[102][102];
int solution(vector<vector<int>> maps)
{
    int ans = -1;
    int n = maps.size(), m = maps[0].size();
    
    for(int i=0; i<n; i++)
        fill(dist[i], dist[i] + m, -1);
    dist[0][0] = 1;
    queue<pair<int, int>> q;
    q.push({0, 0});
    
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        if (cur.first == n-1 && cur.second == m-1) {
            ans = dist[n-1][m-1];    
            break;   
        }
        for(int dir = 0; dir<4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (maps[nx][ny] == 0 || dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
    
    return ans;
    
}