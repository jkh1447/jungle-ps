#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int min_len = 100'001;
    int min_s = 100'001, min_e = 100'001;
    unordered_map<string, int> j;
    
    for(string s: gems) {
        j[s] = 0;
    }

    int e = 0;
    int cnt = 0;
    for (int s=0; s<gems.size(); s++) {
        if (s > e) continue;
        while (e < gems.size() && cnt != j.size()) {
            if (gems[e] == gems[s] && j[gems[e]] >= 1) break;
            j[gems[e]]++;    
            if (j[gems[e]] == 1) cnt++;
            e++;
        }

        
        if (cnt == j.size() && e - s < min_len) {
            min_len = min(min_len, e-s);
            
            min_s = s+1;
            min_e = e;    

        }
        
        j[gems[s]]--;
        if (j[gems[s]] == 0) cnt--;
        
    }
    
    answer.push_back(min_s);
    answer.push_back(min_e);
    
    return answer;
}