#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> adj(n+1);
    vector<int> dist(n+1, -1);
    dist[1] = 0;
    
    for(auto nxt: edge){
        int a, b;
        a = nxt[0]; b = nxt[1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    queue<int> q;
    q.push(1);
    
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto nxt: adj[cur]) {
            if (dist[nxt] >= 0) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }

    int maxval = *max_element(dist.begin(), dist.end());    
    for(int i=1; i<=n; i++){
        if(dist[i] == maxval) answer++;
    }
    
    return answer;
}