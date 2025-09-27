#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> m;
    
    for(string name: participant){
        m[name]++;
    }
    
    for(string name: completion){
        if(m.find(name) != m.end()){
            m[name]--;
        }
    }
    
    for(pair<string, int> cur: m){
        if (cur.second != 0) {
            answer = cur.first;
            break;
        }
    }
    
    return answer;
}