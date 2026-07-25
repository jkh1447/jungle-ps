#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int cnt = 0;
    stack<int> s;
    
    for(int i=0; i<number.size(); i++) {
        int cur = number[i] - '0';
        while(!s.empty() && s.top() < cur && cnt < k) {
            s.pop();
            cnt++;
        }
        s.push(cur);

    }
    if (cnt < k) {
        int time = k-cnt;
        while(time--) s.pop();
    }
    
    while(!s.empty()) {
        string tmp = to_string(s.top());
        s.pop();
        answer += tmp;
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}