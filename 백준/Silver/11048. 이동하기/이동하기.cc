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

int n, m;
int board[1010][1010];


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = board[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vector<pair<int, int>> dirs = { {i + 1, j}, {i, j + 1}, {i + 1, j + 1} };
            for (auto nxt : dirs) {
                if (nxt.X < 0 || nxt.X >= n || nxt.Y < 0 || nxt.Y >= m) continue;
                dp[nxt.X][nxt.Y] = max(dp[nxt.X][nxt.Y], dp[i][j] + board[nxt.X][nxt.Y]);
            }
        }
    }
    cout << dp[n - 1][m - 1];
}