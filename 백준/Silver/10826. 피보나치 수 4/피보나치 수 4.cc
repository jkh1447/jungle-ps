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

vector<string> dp(10001);


string add(string a, string b) {
    string res = "";
    int carry = 0;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int n = max(a.size(), b.size());
    for (int i = 0; i < n; i++) {
        int x = (i < a.size()) ? a[i] - '0' : 0;
        int y = (i < b.size()) ? b[i] - '0' : 0;
        int sum = x + y + carry;
        res.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    if (carry) res.push_back(carry + '0');
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    dp[0] = "0";
    dp[1] = "1";
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        dp[i] = add(dp[i - 1], dp[i - 2]);
    }
    cout << dp[n];
}