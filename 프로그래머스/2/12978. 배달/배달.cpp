#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct Node {
  int cost, u;  
};

struct Cmp {
  bool operator()(const Node& a, const Node& b) const {
      return a.cost < b.cost;
  }  
};

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    int INF = 1e9;
    vector<int> dist(N+1, INF); 
    priority_queue<Node, vector<Node>, Cmp> pq;
    pq.push({0, 1});
    dist[1] = 0;
    
    vector<vector<Node>> adj(N+1);
    for(int i=0; i<road.size(); i++) {
        int u, v, cost;
        u = road[i][0];
        v = road[i][1];
        cost = road[i][2];
        adj[u].push_back({cost, v});
        adj[v].push_back({cost, u});
    }
    
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (dist[cur.u] != cur.cost) continue;
        
        for(auto& nxt: adj[cur.u]) {
            if (dist[nxt.u] <= cur.cost + nxt.cost) continue;
            dist[nxt.u] = cur.cost + nxt.cost;
            pq.push({dist[nxt.u], nxt.u});
        }
    }
    
    for(int i=1; i<=N; i++) {
        if (dist[i] <= K) answer++;
    }

    return answer;
}