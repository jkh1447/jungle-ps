#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int n = nums.size() / 2;
    set<int> s;
    for(int nxt: nums) s.insert(nxt);
    if(s.size() >= n) answer = n;
    else if (s.size() < n) answer = s.size();
    
    return answer;
}