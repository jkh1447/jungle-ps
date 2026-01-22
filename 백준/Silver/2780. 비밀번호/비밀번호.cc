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

int dp[10][1001];
vector<int> adj[10];
int MOD = 1234567;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;

    adj[0].push_back(7);
    adj[1].push_back(2);
    adj[1].push_back(4);
    adj[2].push_back(1);
    adj[2].push_back(5);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(6);
    adj[4].push_back(1);
    adj[4].push_back(5);
    adj[4].push_back(7);
    adj[5].push_back(2);
    adj[5].push_back(4);
    adj[5].push_back(6);
    adj[5].push_back(8);
    adj[6].push_back(3);
    adj[6].push_back(5);
    adj[6].push_back(9);
    adj[7].push_back(0);
    adj[7].push_back(4);
    adj[7].push_back(8);
    adj[8].push_back(5);
    adj[8].push_back(7);
    adj[8].push_back(9);
    adj[9].push_back(6);
    adj[9].push_back(8);


    for (int i = 0; i < 10; i++) dp[i][1] = 1;

    for (int j = 2; j < 1001; j++) {
        for (int i = 0; i < 10; i++) {
            for (int nxt : adj[i]) {
                dp[i][j] += dp[nxt][j - 1];
                dp[i][j] %= MOD;
            }
        }
    }



    while (T--) {
        int n;
        cin >> n;

        int hap = 0;
        for (int i = 0; i < 10; i++) {
            hap += dp[i][n];
            hap %= MOD;
        }

        cout << hap << "\n";
    }
}