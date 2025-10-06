#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// 110
// 111
// 011

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<int> vis(n+1, 0);
    for(int i=0; i<n; i++){
        if(vis[i]) continue;
        answer++;
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for(int j=0; j<computers[cur].size(); j++){
                if(computers[cur][j] == 0 || vis[j]) continue;
                vis[j] = 1;
                q.push(j);
            }
        }
    }
    return answer;
}