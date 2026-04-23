#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct Schedule {
    string name;
    int start;
    int playtime;
};

vector<string> split(string s, string deli) {
    vector<string> tokens;
    int pos = 0;
    while(pos < s.size()) {
        int nxt_pos = s.find(deli, pos);
        if (nxt_pos == -1) nxt_pos = s.size();
        if (nxt_pos - pos > 0)
            tokens.push_back(s.substr(pos, nxt_pos - pos));
        pos = nxt_pos + deli.size();
    }
    return tokens;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<Schedule> sches;
    
    for(auto& s: plans) {
        vector<string> tokens = split(s[1], ":");
        int start = stoi(tokens[0]) * 60 + stoi(tokens[1]);
        sches.push_back({s[0], start, stoi(s[2])});
    }
    
    // 시작 시간 순 정렬
    sort(sches.begin(), sches.end(), [](const Schedule& a, const Schedule& b) {
        return a.start < b.start;
    });

    stack<Schedule> q;
    Schedule curS = {"", -1, -1}; // 현재 진행 중인 과제 (비어있음 표시)
    int planIdx = 0;

    // 모든 과제를 시작하거나 스택이 빌 때까지 반복
    // 1분 단위가 아니라 "이벤트가 발생하는 시간"으로 점프하면 더 좋지만, 
    // 1분 단위로 짠다면 아래와 같습니다.
    for (int time = sches[0].start; ; time++) {
        
        // 1. 새로운 과제가 시작될 시간인가?
        if (planIdx < sches.size() && sches[planIdx].start == time) {
            // 하던 게 있다면 스택에 보관
            if (curS.name != "") {
                q.push(curS);
            }
            curS = sches[planIdx++];
        }

        // 2. 현재 진행 중인 과제가 있다면 1분 진행
        if (curS.name != "") {
            curS.playtime--;
            
            // 3. 과제를 끝냈다면?
            if (curS.playtime == 0) {
                answer.push_back(curS.name);
                
                // 스택에서 다음 과제 가져오기
                if (!q.empty()) {
                    curS = q.top();
                    q.pop();
                } else {
                    curS = {"", -1, -1}; // 더 할 게 없음
                }
            }
        }

        // 종료 조건: 모든 계획을 시작했고, 현재 과제도 없고, 스택도 비었을 때
        if (planIdx >= sches.size() && curS.name == "" && q.empty()) break;
    }
    
    return answer;
}