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


bool visited[61][61][61];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> dmg = {
        {9,3,1},{9,1,3},{3,9,1},
        {3,1,9},{1,9,3},{1,3,9}
    };

    int n;
    cin >> n;
    vector<int> v(3, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    queue<tuple<int, int, int, int>> q;
    q.push({ v[0], v[1], v[2], 0 });
    visited[v[0]][v[1]][v[2]] = true;

    while (!q.empty()) {
        int a, b, c, cnt;
        tie(a, b, c, cnt) = q.front();
        q.pop();

        if (a == 0 && b == 0 && c == 0) {
            cout << cnt;
            break;
        }

        for (auto cur : dmg) {
            int na = max(a - cur[0], 0);
            int nb = max(b - cur[1], 0);
            int nc = max(c - cur[2], 0);

            vector<int> tmp = { na, nb, nc };
            sort(tmp.begin(), tmp.end());
            na = tmp[0], nb = tmp[1], nc = tmp[2];

            if (!visited[na][nb][nc]) {
                visited[na][nb][nc] = true;
                q.push({ na, nb, nc, cnt + 1 });
            }
        }
    }
    
}