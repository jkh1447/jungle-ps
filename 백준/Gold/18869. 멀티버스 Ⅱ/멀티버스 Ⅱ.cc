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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int s, n;

    cin >> s >> n;
    vector<vector<int>> v(s, vector<int>(n));
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    }
    vector<vector<int>> rank(s, vector<int>(n));

    for (int i = 0; i < s; i++) {
        vector<pair<int, int>> tmp;
        for (int j = 0; j < n; j++) {
            tmp.push_back({ v[i][j], j });
        }

        sort(tmp.begin(), tmp.end());

        int r = 0;
        rank[i][tmp[0].Y] = 0;

        for (int j = 1; j < n; j++) {
            if (tmp[j].X != tmp[j - 1].X) r++;
            rank[i][tmp[j].Y] = r;
        }
    }

    int ans = 0;
    for (int i = 0; i < s; i++) {
        for (int j = i + 1; j < s; j++) {
            if (rank[i] == rank[j]) {
                ans++;
            }
        }
    }

    cout << ans;
}