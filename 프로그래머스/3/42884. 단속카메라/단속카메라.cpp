#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(), routes.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });
    
    int end = routes[0][1];
    for(int i=1; i<routes.size(); i++){
        if (routes[i][0] <= end) continue;
        else {
            answer++;
            end = routes[i][1];
        }
    }
    
    return answer;
}