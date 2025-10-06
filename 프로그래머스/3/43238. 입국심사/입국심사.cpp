#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long maxt = *max_element(times.begin(), times.end()) * (long long)n;
    long long st = 0;
    long long en = maxt;
    long long ans = 0;
    
    while(st <= en) {
        long long mid = (st+en) / 2;
        long long hap = 0;
        for(int i=0; i<times.size(); i++){
            hap += mid / times[i];
        }
        if(hap >= n) {
            ans = mid;
            en = mid - 1;
        }
        else {
            st = mid + 1;
        }
    }
    
    answer = ans;
    
    return answer;
}