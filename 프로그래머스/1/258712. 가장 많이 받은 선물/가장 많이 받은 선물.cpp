#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<string> split(string s, string delimiter){
    vector<string> tokens;
    int pos = 0;
    while(pos < s.size()){
        int nxt_pos = s.find(delimiter, pos);
        if(nxt_pos == -1) nxt_pos = s.size();
        if(nxt_pos - pos > 0) 
            tokens.push_back(s.substr(pos, nxt_pos-pos));
        pos = nxt_pos + 1;
    }
    return tokens;
}
unordered_map<string, unordered_map<string, int>> m1;
unordered_map<string, pair<int ,int>> m2; // 준거, 받은거
unordered_map<string, int> m3;
int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    for(string cur: gifts){
        vector<string> tok = split(cur, " ");
        m1[tok[0]][tok[1]]++;
        m2[tok[0]].first++;
        m2[tok[1]].second++;
    }
    
    for(int i=0; i<friends.size(); i++) {
        for(int j=i+1; j<friends.size(); j++){
            string a = friends[i];
            string b = friends[j];
            
            int a_to_b = m1[a][b];
            int b_to_a = m1[b][a];
            
            if (a_to_b > b_to_a){
                m3[a]++;
            }
            else if (a_to_b < b_to_a){
                m3[b]++;
            }
            else {
                int scoreA = m2[a].first - m2[a].second;
                int scoreB = m2[b].first - m2[b].second;
                if(scoreA > scoreB){
                    m3[a]++;
                }
                else if (scoreA < scoreB) m3[b]++;
            }
            
        }
    }
    
    for (auto &p : m3) {
        answer = max(answer, p.second);
    }

    
    return answer;
}