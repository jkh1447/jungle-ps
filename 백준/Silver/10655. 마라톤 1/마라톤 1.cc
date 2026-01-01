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
int dy[4] = { 0, -1, 0, 1 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({ x, y });
    }
    int ans = 0x7fffffff;
    int hap = 0;
    vector<int> dist;
    for (int i = 0; i < n - 1; i++) {
        int d = abs(v[i].X - v[i + 1].X) + abs(v[i].Y - v[i + 1].Y);
        hap += d;
        dist.push_back(d);
    }
    for (int i = 1; i < n - 1; i++) {
        int newDist = abs(v[i - 1].X - v[i + 1].X) + abs(v[i - 1].Y - v[i + 1].Y);
        ans = min(ans, hap - dist[i - 1] - dist[i] + newDist);
    }
    cout << ans;
}
