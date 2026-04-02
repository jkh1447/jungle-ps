#include <string>
#include <vector>

using namespace std;

int dp[1001][51];
int MAX = 1e9;
int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    int answer = MAX;
    
    temperature += 10;
    t1 += 10;
    t2 += 10;
    
    for(int i=0; i<1001; i++)
        fill(dp[i], dp[i]+51, MAX);
    dp[0][temperature] = 0;
    
    for(int i=0; i<onboard.size()-1; i++){
        for(int j=0; j<51; j++) {
            if(dp[i][j] == MAX) continue;
            
            int nxt_t = j;
            if (j < temperature) nxt_t = j + 1;
            if (j > temperature) nxt_t = j - 1;
            if (nxt_t <= 50 && nxt_t >= 0) dp[i+1][nxt_t] = min(dp[i+1][nxt_t], dp[i][j]);
            

            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + b);
 
            
            if (j+1 <= 50) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + a);
            if (j-1 >= 0) dp[i+1][j-1] = min(dp[i+1][j-1], dp[i][j] + a);
        }
        
        if (onboard[i+1] == 1) {
            for(int j=0; j<51; j++){
                if (j < t1 || j > t2) dp[i+1][j] = MAX;
            }
        }
    }
    
    for(int j=0; j<51; j++){
        answer = min(answer, dp[onboard.size()-1][j]);    
    }
    
    return answer;
}