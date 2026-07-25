#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int dist[201];
int distS[201];
int INF = 1e9;
vector<pair<int,int>> adj[201];

void dijkstra(int start) {
    fill(dist, dist + 201, INF);
    
    priority_queue<pair<int ,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (dist[cur.second] != cur.first) continue;
        
        for (auto nxt: adj[cur.second]) {
            if (dist[nxt.second] > dist[cur.second] + nxt.first) {
                dist[nxt.second] = dist[cur.second] + nxt.first;
                pq.push({dist[nxt.second], nxt.second});
            }
        }
    }
    
    
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 1e9;
    
    for (int i=0; i<fares.size(); i++) {
        adj[fares[i][0]].push_back({fares[i][2], fares[i][1]});
        adj[fares[i][1]].push_back({fares[i][2], fares[i][0]});
    }
    
    dijkstra(s);
    for(int i=0; i<201; i++) distS[i] = dist[i];
    
    
    for (int i=1; i<=n; i++) {
        dijkstra(i);
        
        int weight = 0;
        if (distS[i] == INF || dist[a] == INF || dist[b] == INF) continue;
        weight += distS[i] + dist[a] + dist[b];
        
        answer = min(answer, weight);
        
    }
    
    return answer;
}