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

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int t = 0; t < 3; t++) {
        int N;
        cin >> N;
        int sum = 0;
        vector<pair<int, int>> coins;
        for (int i = 0; i < N; i++) {
            int coin, n;
            cin >> coin >> n;
            coins.push_back({ coin, n });
            sum += coin * n;
        }

        if (sum % 2 != 0) {
            cout << 0 << "\n";
            continue;
        }

        // sort(coins.begin(), coins.end());
        int half = sum / 2;
        vector<int> dp(half + 1);
        dp[0] = 1;

        for (int i = 1; i <= N; i++) {
            int coin = coins[i-1].X, n = coins[i-1].Y;
            for (int j = half; j >= coin; j--) {
                for (int k = 1; k <= n; k++) {
                    if (j - coin * k < 0) break;
                    if (dp[j - coin * k] == 1) {
                        dp[j] = 1;
                    }
                }
            }
        }
        //cout << "\n";
        //for (int i = 0; i <= N; i++) {
        //    for (int j = 0; j < half + 1; j++) {
        //        cout << dp[i][j] << " ";
        //    }
        //    cout << "\n";
        //}
        cout << dp[half] << "\n";
    }
}
