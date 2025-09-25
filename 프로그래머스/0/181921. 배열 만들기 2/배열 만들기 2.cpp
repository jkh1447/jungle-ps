#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    for(int i=l; i<=r; i++){
        string cur = to_string(i);
        bool flag = false;
        for(int j=0; j<cur.size(); j++){
            if (cur[j] != '5' && cur[j] != '0') {
                flag = true;
                break;
            }
        }
        if(!flag) answer.push_back(stoi(cur));
    }
    if(answer.size() == 0) answer.push_back(-1);
    return answer;
}