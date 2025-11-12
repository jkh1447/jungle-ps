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
vector<int> vis;
vector<int> adj[500'001];

int find(int u) {
    if (vis[u] < 0) return u;
    return vis[u] = find(vis[u]);
}

bool uni(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    vis[v] = u;
    return true;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    vis.resize(n+1, -1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        
        if (!uni(a, b)) {
            cout << i + 1;
            return 0;
        }
    }

    cout << 0;
}