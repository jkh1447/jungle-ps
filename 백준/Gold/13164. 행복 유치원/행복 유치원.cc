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

    int n, k;

    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<pair<int, int>> diff(n - 1);
    for (int i = 0; i < n - 1; i++) {
        diff[i] = { v[i + 1] - v[i], i };
    }
    vector<int> idx;
    sort(diff.begin(), diff.end(), greater<pair<int, int>>());
    for (int i = 0; i < k-1; i++) {
        idx.push_back(diff[i].Y);
    }
    sort(idx.begin(), idx.end());
    int cur = 0;
    int ans = 0;
    for (int i = 0; i < idx.size(); i++) {
        ans += v[idx[i]] - v[cur];
        cur = idx[i] + 1;
    }
    ans += v[v.size() - 1] - v[cur];

    cout << ans;
}