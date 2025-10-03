#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n){
    if (n<=1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for(long long i=2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string num = "";
    int cur = n;
    while(cur > 0){
        int digit = cur % k;
        cur = cur / k;
        num = to_string(digit) + num;
    }
    
    string number = "";
    for(int i=0; i<num.size(); i++){
        if(num[i]=='0'){
            if(number.empty()) continue;
            if(isPrime(stoll(number))) answer++;
            number.clear();
        }
        else {
            number += num[i];
        }
    }

    if(!number.empty()) {
        if(isPrime(stoll(number))) answer++;
    }
    
    return answer;
}