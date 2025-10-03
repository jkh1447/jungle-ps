#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    unordered_map<string, int> idx;
    for(int i=0; i<id_list.size(); i++) idx[id_list[i]] = i;
    unordered_map<string, set<string>> m1;
    unordered_map<string, int> m2;
    
    for(auto cur: report) {
        stringstream ss(cur);
        string from, to;
        ss >> from >> to;
        if(m1[from].find(to) != m1[from].end()) continue;
        m1[from].insert(to);
        m2[to]++;
    }
    
    for(auto cur: m2){
        if (cur.second >= k){
            for(string name: id_list){
                if(m1[name].find(cur.first) != m1[name].end()){
                    answer[idx[name]]++;
                }
            }
        }
    }
    
    return answer;
}