#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>()); // 내림차순
    
    int h = 0;
    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] >= i+1) {
            h = i+1;
        } else {
            break;
        }
    }
    return h;
}