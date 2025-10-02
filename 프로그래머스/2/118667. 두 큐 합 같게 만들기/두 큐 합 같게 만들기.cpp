#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    deque<int> qu1(queue1.begin(), queue1.end());
    deque<int> qu2(queue2.begin(), queue2.end());
    long long answer = 0;
    long long all = 0, q1 = 0, q2 = 0;
    for(int i=0; i<queue1.size(); i++) {
        all += queue1[i] + queue2[i];
        q1 += queue1[i];
        q2 += queue2[i];
    }
    
    if (all % 2 != 0) return -1;
    bool flag = false;
    while(q1 != q2) {
        if (qu1.empty() || qu2.empty()) {
            flag = true;
            break;
        }
        if (answer > queue1.size() * 2 + 1 ) return -1;
        if (q1 < q2) {
            qu1.push_back(qu2[0]);
            q1 += qu2[0];
            q2 -= qu2[0];
            qu2.pop_front();
            
        }
        else {
            qu2.push_back(qu1[0]);
            q2 += qu1[0];
            q1 -= qu1[0];
            qu1.pop_front();
        }
        answer++;
    }
    
    if (flag) return -1;
    return answer;
}