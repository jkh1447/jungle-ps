#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int zero = 0;
    int time = 0;
    
    while(s != "1") {
        string no_zero_s = "";
        for(int i=0; i<s.size(); i++){
            if(s[i] == '0') zero++;
            else no_zero_s += '1';
        }
        
        int c = no_zero_s.size();
        
        string new_s = "";
        
        while(c != 0) {
            new_s += to_string(c % 2);
            c /= 2;
        }
        
        reverse(new_s.begin(), new_s.end());
        s = new_s;
        time++;
    }
    
    answer.push_back(time);
    answer.push_back(zero);
    
    return answer;
}