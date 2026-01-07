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

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };
//
//int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
//int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int n, m;
vector<int> adj[101];
vector<int> combi;
int ans = 0;
int a = 9999, b = 9999;
void dfs(int cnt, int s, vector<int>& p) {
    if (cnt == 2) {
        queue<int> q;
        vector<int> dist(n, -1);
        dist[p[0]] = 0; dist[p[1]] = 0;
        q.push(p[0]); q.push(p[1]);
        int hap = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            hap += dist[cur] * 2;

            for (int nxt : adj[cur]) {
                if (dist[nxt] >= 0) continue;
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
        if (ans == 0) {
            ans = hap;
            a = p[0];
            b = p[1];
        }
        else if (hap <= ans) {
            if (p[0] > p[1]) swap(p[0], p[1]);
            if (a > p[0]) {
                ans = hap;
                a = p[0];
                b = p[1];
            }
            else if (a == p[0] && b > p[1]) {
                ans = hap;
                a = p[0];
                b = p[1];
            }
        }

        return;
    }
    for (int i = s; i < n; i++) {
        p.push_back(i);
        dfs(cnt + 1, i + 1, p);
        p.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    cin >> n >> m;
    combi.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    vector<int> p;
    dfs(0, 0, p);
    cout << a+1 << " " << b+1 << " " << ans;
}