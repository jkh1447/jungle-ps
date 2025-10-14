#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stack>
#include <deque>
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<vector<int>> v(2, vector<int>(n, 0));
        vector<vector<int>> dp(2, vector<int>(n, 0));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) cin >> v[i][j];
        }
        dp[0][0] = v[0][0]; dp[1][0] = v[1][0];
        dp[0][1] = dp[1][0] + v[0][1]; 
        dp[1][1] = dp[0][0] + v[1][1];
        for (int i = 2; i < n; i++) {
            dp[0][i] = v[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
            dp[1][i] = v[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
        }

        cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n";

    }
    

}