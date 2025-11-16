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




int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));

    for (int i = 1; i <= n; i++) dp[i][i] = true;
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i < j; i++) {
            if (j - i > 1) {
                dp[i][j] = v[i-1] == v[j-1] && dp[i + 1][j - 1];
            }
            else {
                dp[i][j] = v[i-1] == v[j-1];
            }
        }
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        cout << dp[s][e] << "\n";
    }
}