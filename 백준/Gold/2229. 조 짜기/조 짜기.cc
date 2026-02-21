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

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };

//int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
//int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = i-1; j >= 0; j--) {
            int maxv = 0;
            int minv = 100000;
            for (int k = j + 1; k <= i; k++) {
                maxv = max(v[k], maxv);
                minv = min(v[k], minv);
            }
            dp[i] = max(dp[i], dp[j] + maxv - minv);
        }
    }

    cout << dp[n];
}