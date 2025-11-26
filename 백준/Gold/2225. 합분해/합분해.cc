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

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };

int DIV = 1'000'000'000;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));
    for (int i = 0; i < N + 1; i++) dp[1][i] = 1;
    for (int i = 1; i < K + 1; i++) dp[i][0] = 1;
    for (int i = 2; i <= K; i++) {
        for (int j = 1; j < N + 1; j++) {
            
            dp[i][j] = (dp[i - 1][j] + dp[i][j-1]) % DIV;
           
        }
    }
    cout << dp[K][N] % DIV;
}