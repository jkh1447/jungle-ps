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
#define LL long long

//int dx[4] = { 1, 0, -1, 0 };
//int dy[4] = { 0, 1, 0, -1 };
//
//int dx[4] = { -1, 0, 1, 0 };
//int dy[4] = { 0, 1, 0, -1 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };

//int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
//int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int MOD = 1'000'000'007;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // if (i == 0 && j == 0) continue;
            if (i == 0 || j == 0) dp[i][j] = 1;
            else {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= MOD;
                dp[i][j] += dp[i - 1][j-1];
                dp[i][j] %= MOD;
                dp[i][j] += dp[i][j-1];
                dp[i][j] %= MOD;
            }
            dp[i][j] %= MOD;
        }
    }

    cout << dp[n - 1][m - 1];
}