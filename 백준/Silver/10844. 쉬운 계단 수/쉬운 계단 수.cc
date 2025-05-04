#include <iostream>
#include <algorithm>
using namespace std;


int dp[101][11];

int main(){
    int n;
    cin >> n;

    dp[1][0] = 0;
    for(int i=1; i<10; i++) dp[1][i] = 1;

    if(n > 1){
        for(int i=2; i<n+1; i++){
            for(int j=0; j<10; j++){
                if(j == 0) dp[i][j] = (dp[i-1][j+1]);
                else if(j == 9) dp[i][j] = (dp[i-1][j-1]);
                else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;
            }
        }
    }


    int ans = 0;
    for(int i=0; i<10; i++){
        ans = (ans + dp[n][i])%1000000000;
    }
    cout << ans;
}