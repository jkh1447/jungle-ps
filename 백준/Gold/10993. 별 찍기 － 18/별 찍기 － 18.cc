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

int n=1, m=1;
vector<vector<char>> v;

void solve(int n, int x, int y) {

    if (n == 1) {
        v[x][y] = '*';
        return;
    }

    int h = (1 << n) - 1;
    int w = (1 << (n + 1)) - 3;

    if (n % 2 == 1) {
        for (int j = 0; j < w; j++) v[x+h-1][y + j] = '*';
        for (int i = 0; i < h; i++) {
            v[x + i][y + (w / 2) - i] = '*';
            v[x + i][y + (w / 2) + i] = '*';
        }

        solve(n - 1, x + h / 2, y+ (1 << (n-1)));
    }
    else {
        for (int j = 0; j < w; j++) v[x][y + j] = '*';
        for (int i = 0; i < h; i++) {
            v[x + i][y + i] = '*';
            v[x + i][y + (w - 1) - i] = '*';
        }

        solve(n - 1, x + 1, y+ (1 << (n - 1)));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N-1; i++) {
        n = n * 2 + 1;
        m = m * 2 + 3;
    }
    v.resize(n, vector<char>(m, ' '));

    solve(N, 0, 0);

    for (int i = 0; i < n; i++) {

        int last_pos = 0;
        for (int j = m - 1; j >= 0; j--) {
            if (v[i][j] == '*') {
                last_pos = j;
                break;
            }
        }

        for (int j = 0; j <= last_pos; j++) {
            cout << v[i][j];
        }
        cout << "\n";
    }
}