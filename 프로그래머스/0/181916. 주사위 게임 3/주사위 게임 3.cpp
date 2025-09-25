#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int a, int b, int c, int d) {
    int answer = 0;
    // table[i]: i번 주사위가 나온 횟수
    int table[7] = {};
    table[a]++; table[b]++; table[c]++; table[d]++;
    // num[i]: i번 나온 주사위 숫자
    vector<int> num[5];
    num[table[1]].push_back(1);
    num[table[2]].push_back(2);
    num[table[3]].push_back(3);
    num[table[4]].push_back(4);
    num[table[5]].push_back(5);
    num[table[6]].push_back(6);
    
    if(!num[4].empty()){
        answer = 1111 * num[4][0];
    }
    else if (!num[3].empty()) {
        answer = pow(10 * num[3][0] + num[1][0], 2);
    }
    else if (num[2].size() >= 2) {
        answer = (num[2][0] + num[2][1]) * abs(num[2][0] - num[2][1]);
    }
    else if (num[2].size() == 1 && num[1].size() > 1){
        answer = num[1][0] * num[1][1];
    }
    else if (num[1].size() > 3){
        sort(num[1].begin(), num[1].end());
        answer = num[1][0];
    }
    return answer;
}