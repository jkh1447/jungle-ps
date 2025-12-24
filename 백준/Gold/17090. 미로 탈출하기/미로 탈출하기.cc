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
int n, m;
int ok[501][501];
char board[501][501];
int ans;

bool dfs(int x, int y) {

    if (x < 0 || x >= n || y < 0 || y >= m) return true;
    if (ok[x][y] == 1) return false;
    if (ok[x][y] == 2) return true;
    if (ok[x][y] == 3) return false;

    ok[x][y] = 1;

    int nx = x, ny = y;
    char dir = board[x][y];
    if (dir == 'U') nx -= 1;
    else if (dir == 'D') nx += 1;
    else if (dir == 'R') ny += 1;
    else if (dir == 'L') ny -= 1;
    
    if (dfs(nx, ny)) ok[x][y] = 2;
    else ok[x][y] = 3;

    return ok[x][y] == 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dfs(i, j)) ans++;
        }
    }
    cout << ans;
}

