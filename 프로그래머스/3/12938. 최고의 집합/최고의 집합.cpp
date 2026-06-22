#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if (s / n == 0 ) return {-1};
    
    int a = s / n;
    int b = s % n;
    answer.reserve(n);
    for(int i=0; i<n-b; i++){
        answer.push_back(a);
    }
    for(int i=0; i<b; i++){
        answer.push_back(a+1);
    }
    return answer;
}