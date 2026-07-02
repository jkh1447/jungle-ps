#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<string> path;
vector<string> answer;
vector<bool> vis;
int an = 0;
int cnt = 0;
bool done = false;
void solve(vector<vector<string>>& t, string cur){
    if (done) return;
    
    if (an == cnt) {
        answer = path;
        done = true;
        return;
    }
    
    for (int i=0; i<t.size(); i++) {

        if (!vis[i] && t[i][0] == cur) {
            
            path.push_back(t[i][1]);
            cnt++;
            vis[i] = true;
            solve(t, t[i][1]);
            
            if (done) return;
        
            cnt--;
            vis[i] = false;
            path.pop_back();    
        }
        
        
    }
        
    
}

vector<string> solution(vector<vector<string>> tickets) {
    
    sort(tickets.begin(), tickets.end());
    
    an = tickets.size();
    vis.assign(an, false);
    
    path.push_back("ICN");
    solve(tickets, "ICN");

    return answer;
}