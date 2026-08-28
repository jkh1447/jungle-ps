#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int n = 0;
int t =0;
void dfs(vector<int>& numbers, int i, int hap) {
    if (i == n) {
        if (hap == t) 
            ans++;
        return;
    }
    dfs(numbers, i+1, hap + numbers[i]);
    dfs(numbers, i+1, hap - numbers[i]);
}

int solution(vector<int> numbers, int target) {
    t = target;
    n = numbers.size();
    
    dfs(numbers, 1, numbers[0]);
    dfs(numbers, 1, -numbers[0]);
    
    return ans;
}