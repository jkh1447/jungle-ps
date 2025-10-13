#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    for (int i = 0; i < lost.size(); ) {
        auto it = find(reserve.begin(), reserve.end(), lost[i]);
        if (it != reserve.end()) {
            reserve.erase(it);
            lost.erase(lost.begin() + i);
        } else {
            i++;
        }
    }
    int cnt = 0;
    sort(lost.begin(), lost.end());
    for(int i=0; i<lost.size(); i++) {
        auto idx = find(reserve.begin(), reserve.end(), lost[i] - 1);
        if(idx != reserve.end()) {
            reserve.erase(idx);
            continue;
        }
        idx = find(reserve.begin(), reserve.end(), lost[i] + 1);
        if(idx != reserve.end()) {
            reserve.erase(idx);
            continue;
        }
        
        cnt++;
    }
    answer = n-cnt;
    
    return answer;
}