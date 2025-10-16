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
    

    int N;
    cin >> N;
    vector<vector<int>> v(N, vector<int>(N));
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(3, 0)));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
        }
    }

    int d = 1;
    for (int i = 1; i < N; i++) {
        if (v[0][i] == 1) break;
        else dp[0][i][0] = d;
    }



    for (int i = 1; i < N; i++) {
        for (int j = 2; j < N; j++) {
            if (v[i][j] == 1) continue;
            dp[i][j][0] = dp[i][j - 1][0] + dp[i][j-1][2];
            dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];
            if(v[i-1][j] != 1 && v[i][j-1] != 1 && v[i-1][j-1]!=1)
                dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];

        }
    }

    cout << dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2] << "\n";

}