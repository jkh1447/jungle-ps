#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<int>& stones, int n, int k) {
    int cnt= 0;
    for(int i=0; i<stones.size(); i++){
        if (stones[i] < n) {
            cnt++;
            if (cnt >= k) return false;
        } else {
            cnt = 0;
        }
    }
    
    return true;
}

int solution(vector<int> stones, int k) {
    int st = 0, en = 200000000;
    int ans = 0;
    while(st <= en) {
        int mid = (st+en)/2;
        
        if (isPossible(stones, mid, k)) {
            ans = mid;
            st = mid + 1;
        }    
        else {
            en = mid - 1;
        }
    }
    return ans;
}