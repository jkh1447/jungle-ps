#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map <char, int> m;
    for(int i=0; i<survey.size(); i++){
        int cur = choices[i];
        if (cur == 4) continue;
        
        if(cur < 4){
            m[survey[i][0]] += 4 - cur;
        }
        else if (cur > 4){
            m[survey[i][1]] += cur - 4;
        }
    }
    
    if(m['R'] == m['T']) answer += "R";
    else if(m['R'] > m['T']) answer += "R";
    else answer += "T";
    
    if(m['C'] == m['F']) answer += "C";
    else if(m['C'] > m['F']) answer += "C";
    else answer += "F";
    
    if(m['J'] == m['M']) answer += "J";
    else if(m['J'] > m['M']) answer += "J";
    else answer += "M";
    
    if(m['A'] == m['N']) answer += "A";
    else if(m['A'] > m['N']) answer += "A";
    else answer += "N";
    
    return answer;
}