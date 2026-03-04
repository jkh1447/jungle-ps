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
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

//int dx[4] = { -1, 0, 1, 0 };
//int dy[4] = { 0, 1, 0, -1 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };

//int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
//int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int n, m;
vector<int> v;
vector<int> vis;
set<vector<int>> ans;
void solve(int cnt, vector<int> &p) {

    if (cnt == m) {
        ans.insert(p);
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        if (!p.empty() && p.back() >= v[i]) continue;
        vis[i] = 1;
        p.push_back(v[i]);
        solve(cnt + 1, p);
        p.pop_back();
        vis[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }
    vis.resize(n, 0);

    vector<int> path;
    solve(0, path);


    for (vector<int> cur : ans) {
        for (int i = 0; i < cur.size(); i++) cout << cur[i] << " ";
        cout << "\n";
    }
}