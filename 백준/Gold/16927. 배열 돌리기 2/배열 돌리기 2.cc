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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    LL r;
    cin >> n >> m >> r;
    vector<vector<LL>> v(n, vector<LL>(m));


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }


    int layers = min(n, m) / 2;
    for (int l = 0; l < layers; l++) {
        vector<int> t;

        for (int i = l; i < m-l; i++) t.push_back(v[l][i]);
        for (int i = l + 1; i < n-l; i++) t.push_back(v[i][m - 1 - l]);
        for (int i = m - 2 - l; i >= l; i--) t.push_back(v[n - 1 - l][i]);
        for (int i = n - 2 - l; i > l; i--) t.push_back(v[i][l]);

        rotate(t.begin(), t.begin() + (r % t.size()), t.end());

        int idx = 0;

        for (int i = l; i < m - l; i++) v[l][i] = t[idx++];
        for (int i = l + 1; i < n - l; i++) v[i][m - 1 - l] = t[idx++];
        for (int i = m - 2 - l; i >= l; i--) v[n - 1 - l][i] = t[idx++];
        for (int i = n - 2 - l; i > l; i--) v[i][l] = t[idx++];


    }



    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}