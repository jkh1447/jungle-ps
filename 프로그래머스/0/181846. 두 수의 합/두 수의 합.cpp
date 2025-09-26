#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(string a, string b) {
    string answer = "";
    int alen = a.size();
    int blen = b.size();
    
    int carry = 0;
    for(int i=1; i<=max(alen, blen); i++) {
        int numa = i > alen ? 0 : (a[alen-i] - '0');
        int numb = i > blen ? 0 : (b[blen-i] - '0');
        
        int hap = numa + numb + carry;
        
        if(hap >= 10) carry = 1;
        else carry = 0;
        
        answer = to_string(hap % 10) + answer;
        
    }
    if(carry) answer = '1' + answer;
    
    return answer;
}