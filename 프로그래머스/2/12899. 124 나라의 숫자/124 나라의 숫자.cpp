#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(int n) {
    string answer = "";
    
    while(n != 0) {
        int mod = n % 3;
        int q = n / 3;
        
        if (mod == 0) {
            answer = "4" + answer;    
            q--;
        }
        else answer = to_string(mod) + answer;
        
        n = q;
    }
    
    return answer;
}