#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int dp[41][201];
int MAX = 1e9;
int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    
    int len = info.size();

    for (int i = 0; i <= len; i++) {
        for (int j = 0; j < m; j++) dp[i][j] = MAX;
    }
    dp[0][0] = 0;
    
    for(int i=0; i<len; i++){
        int as = info[i][0];
        int bs = info[i][1];
        
        for(int j=0; j<m; j++){
            if (dp[i][j] == MAX) continue;
            
            if (dp[i][j] + as < n) {
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]+as);
            }
            
            if(j + bs < m) {
                dp[i+1][j+bs] = min(dp[i+1][j+bs], dp[i][j]);
            }
        }
    }
    
    int min_v = 1e9+1;
    for(int i=0; i<m; i++){
        min_v = min(min_v, dp[info.size()][i]);
    }
    if (min_v == 1e9) answer = -1;
    else answer = min_v;
    
    return answer;
}