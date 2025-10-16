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
int n;
vector<int> vis(10001, 0);
vector<pair<int, int>> adj[10001];
vector<int> leaves;
void dfs(int x) {
    if (adj[x].size() == 1) leaves.push_back(x);
    vis[x] = 1;
    for (auto nxt : adj[x]) {
        if (vis[nxt.X]) continue;
        dfs(nxt.X);
    }
    return;
}
int ans = 0;
void dfs2(int x, int sum) {
    if (adj[x].size() == 1) {
        ans = max(sum, ans);
    }

    vis[x] = 1;
    for (auto nxt : adj[x]) {
        if (vis[nxt.X]) continue;
        dfs2(nxt.X, sum + nxt.Y);
    }
    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
        adj[b].push_back({ a, c });
    }

    dfs(1);

    for (int i = 0; i < leaves.size(); i++) {
        fill(vis.begin(), vis.end(), 0);
        dfs2(leaves[i], 0);
    }
    cout << ans;
}