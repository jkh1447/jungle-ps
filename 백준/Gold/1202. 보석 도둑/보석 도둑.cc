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

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> j;
    for (int i = 0; i < n; i++) {
        int m, v;
        cin >> m >> v;
        j.push_back({ m, v });
    }

    sort(j.begin(), j.end());

    vector<int> b; 
    for (int i = 0; i < k; i++) {
        int c;
        cin >> c;
        b.push_back(c);
    }
    sort(b.begin(), b.end());

    LL ans = 0;
    priority_queue<int> pq;
    int idx = 0;

    for (int c : b) {
        while (idx < n && j[idx].X <= c) {
            pq.push(j[idx].Y);
            idx++;
        }
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;
}