#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    int n = 0;
    for(auto nxt: edges){
        n = max(n, max(nxt[0], nxt[1]));
    }
    vector<vector<int>> adj(n + 1);
    vector<int> indegree (n+1, 0);
    vector<int> outdegree (n+1, 0);
    for(auto cur: edges){
        int a, b;
        a = cur[0]; b = cur[1];
        adj[a].push_back(b);
        indegree[b]++;
        outdegree[a]++;
    }
    
    int x;
    int donut = 0, stick = 0, eight = 0;
    for(int i=1; i<=n; i++){
        if(indegree[i] == 0 && outdegree[i] >= 2) {
            x = i;
            break;
        }
    }
    vector<int> visited(n+1 ,0);
    visited[x] = 1;
    for(int nxt: adj[x]){
        queue<int> q;
        q.push(nxt);
        visited[nxt]++;
        int verticies = 0, edgies = 0;
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            
            verticies++;
            for(int nxt: adj[cur]){
                edgies++;
                if(visited[nxt]) continue;
                visited[nxt] = 1;
                q.push(nxt);
            }
        }
        
        if (verticies == edgies) donut++;
        else if (verticies == edgies + 1) stick++;
        else if (verticies == edgies - 1) eight++;
    }
   
    vector<int> answer = {x, donut, stick, eight};
    
    return answer;
}