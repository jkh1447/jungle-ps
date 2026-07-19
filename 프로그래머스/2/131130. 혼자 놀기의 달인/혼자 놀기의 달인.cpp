#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
vector<int> adj(101, -1);
vector<int> vis(101, 0);

int solve(int n) {
    queue<int> q;

    q.push(n);
    vis[n] = 1;
    int cnt = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        cnt++;
        if (vis[adj[cur]] == 1) continue;
        vis[adj[cur]] = 1;
        q.push(adj[cur]);
    }

    return cnt;
}

int solution(vector<int> cards) {

    int ans = 0;
    
    for(int i=0; i<cards.size(); i++) {
        adj[i+1] = cards[i];
    }
    
    for(int j=1; j<cards.size(); j++) {
        int score = solve(j);
        bool flag = false;
        for(int k=j+1; k<=cards.size(); k++){
            if (vis[k] == 1) continue;
            int tmp = solve(k);
            ans = max(ans, score * tmp);
            flag = true;
        }
        if (!flag) ans = max(ans, 0);
        
        fill(vis.begin(), vis.begin() + cards.size() + 1, 0);
    }

    
    cout << ans;
        
    return ans;
}