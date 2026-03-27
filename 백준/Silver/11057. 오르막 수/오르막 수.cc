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

// 아래, 오른쪽, 위, 왼쪽
//int dx[4] = { 1, 0, -1, 0 };
//int dy[4] = { 0, 1, 0, -1 };

//int dx[4] = { -1, 0, 1, 0 };
//int dy[4] = { 0, 1, 0, -1 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };

//int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
//int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int dp[1001][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    for (int i = 0; i < 10; i++) dp[1][i] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= 10007;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans += dp[N][i];
        ans %= 10007;
    }

    cout << ans;
    
}

