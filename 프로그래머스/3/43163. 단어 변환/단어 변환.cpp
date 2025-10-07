#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    if(find(words.begin(), words.end(), target) == words.end()) return 0;
    map<string, int> m;
    queue<string> q;
    q.push(begin);
    m[begin]++;
    while(!q.empty()){
        string cur = q.front(); q.pop();
        if(cur == target) return m[target]-1;
        for(int i=0; i<words.size(); i++){
            if(m[words[i]] > 0) continue;
            int cnt = 0;
            for(int j=0; j<cur.size(); j++){
                if(words[i][j] == cur[j]) cnt++;
            }
            if(cnt == target.size()-1) {
                m[words[i]] = m[cur] + 1;
                q.push(words[i]);
            }
        }
    }
    
    return answer;
}