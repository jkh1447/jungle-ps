#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x;
    int y;
    int dir;
    long long w;
};

struct Compare {
    bool operator()(const Node& a, const Node& b){
        return a.w > b.w;
    }  
};

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int INF = 1e9;
int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(n, vector<int>(4, INF)));
    priority_queue<Node, vector<Node>, Compare> pq;
    dist[0][0][0] = 0;
    Node s = {0, 0, 0, 0};
    pq.push(s);
    
    while(!pq.empty()) {
        Node cur = pq.top(); pq.pop();
        
        
        if (dist[cur.x][cur.y][cur.dir] != cur.w) continue;
        
        for(int dir=0; dir<4; dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (board[nx][ny] == 1) continue;
            
            if ((cur.x == 0 && cur.y == 0) || dir == cur.dir) {
                
                if (dist[nx][ny][dir] > dist[cur.x][cur.y][cur.dir] + 100) {
                    dist[nx][ny][dir] = dist[cur.x][cur.y][cur.dir] + 100;
                    pq.push({nx, ny, dir, dist[nx][ny][dir]});
                }
            }
            else {
                if (dist[nx][ny][dir] > dist[cur.x][cur.y][cur.dir] + 500 + 100) {
                    dist[nx][ny][dir] = dist[cur.x][cur.y][cur.dir] + 500 + 100;
                    pq.push({nx, ny, dir, dist[nx][ny][dir]});
                }
            }
        }
    }

    
    return min(dist[n-1][n-1][0], min(dist[n-1][n-1][1], dist[n-1][n-1][2]));
}