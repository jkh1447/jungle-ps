#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int toDays(const string &date) {
    int y = stoi(date.substr(0, 4));
    int m = stoi(date.substr(5, 2));
    int d = stoi(date.substr(8, 2));
    
    return y * 12 * 28 + m * 28 + d;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    
    unordered_map<string, int> termMap;
    for(auto nxt: terms) {
        string type = nxt.substr(0, nxt.find(' '));
        int months = stoi(nxt.substr(nxt.find(' ')+1));

        termMap[type] = months;
    }
    
    int todayDays = toDays(today);
    
    vector<int> answer;
    
    for(int i=0; i<privacies.size(); i++){
        string p = privacies[i];
        string date = p.substr(0, 10);
        string type = p.substr(11);
        int collectDays = toDays(date);
        int months = termMap[type];
        int expireDay = collectDays + months * 28 - 1;
        cout << expireDay << ", " << todayDays << "\n";
        if(expireDay < todayDays) {
            answer.push_back(i+1);
        }
    }
    
    
    
    return answer;
}