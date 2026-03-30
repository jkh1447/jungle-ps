#include <string>
#include <vector>
#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL getNumber(string s) {
    int length = s.size();
    
    LL num = 0;
    LL mul = 1;
    for(int i=1; i<length; i++){
        mul *= 26;
        num += mul;
    }
    
    LL order = 0;
    LL p = 1;
    for(int i=length-1; i>=0; i--) {
        order += (s[i] - 'a') * p;
        p *= 26;
    }
    return num + order + 1;
}

string numToOrder(LL target) {
    LL len = 1;
    LL cnt = 26;
    
    while(target > cnt) { // 이 숫자가 몇자리 글자인가?
        target -= cnt;
        cnt *= 26;
        len++;
    }
    
    target--;
    string res = "";
    for(int i=len-1; i>=0; i--){
        LL p = 1;
        for(int j=0; j<i; j++) p*=26;
        
        int alphaIdx = target / p;
        res += (char)('a' + alphaIdx);
        target %= p;
    }
    return res;
}

string solution(long long n, vector<string> bans) {
    string answer = "";
    
    vector<LL> banNums;
    for(string cur: bans) {
        banNums.push_back(getNumber(cur));
    }
    sort(banNums.begin(), banNums.end());
    
    LL st = 0;
    LL en = 4e15;
    LL ans = 0;
    while(st <= en) {
        LL mid = (st + en) / 2;
        
        LL m = upper_bound(banNums.begin(), banNums.end(), mid) - banNums.begin();
        
        if (mid - m >= n) {
            ans = mid;
            en = mid - 1;
        }
        else {
            st = mid + 1;
        }
    }
    
    answer = numToOrder(ans);
    
    return answer;
}