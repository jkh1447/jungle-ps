#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

map<string, int> m;
void comb(string &s, int r, int i, string cur){
    if(cur.size()==r) {
        m[cur]++;
        return;
    }
    for(int j=i; j<s.size(); j++){
        comb(s, r, j+1, cur + s[j]);    
    }
}


vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for(int i=0; i<course.size(); i++){
        int c = course[i];
        m.clear();
        for(int j=0; j<orders.size(); j++){
            sort(orders[j].begin(), orders[j].end());
            comb(orders[j], c, 0, "");
        }
        int maxval = 0;
        for(auto nxt: m) {
            if(nxt.second > maxval) maxval = nxt.second;
        }
        for(auto nxt: m) {
            if(nxt.second == maxval && nxt.second >= 2) answer.push_back(nxt.first);
        }
        
    }
    sort(answer.begin(), answer.end());
    
    
    return answer;
}