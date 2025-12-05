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
int a[10];
vector<int> path;
vector<int> vis(10, 0);
set<vector<int>> ans;
void solve() {
    if (path.size() == m) {
        ans.insert(path);
        return;
    }

    for (int i = 0; i < n; i++) {
        path.push_back(a[i]);
        solve();
        path.pop_back();
    }
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];

    solve();

    for (auto nxt : ans) {
        for (int i = 0; i < nxt.size(); i++) {
            cout << nxt[i] << " ";
        }
        cout << "\n";
    }
}