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

// 아래, 오른쪽, 위, 왼쪽
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

//int dx[4] = { -1, 0, 1, 0 };
//int dy[4] = { 0, 1, 0, -1 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };

//int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
//int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

using namespace std;

int N, r, c;

int solve(int N, int r, int c) {
    int half = N / 2;

    if (N == 1) {
        int board[2][2] = { {0, 1}, {2, 3} };
        return board[r][c];
    }

    if (r < half && c >= half) {
        return solve(half, r, c - half) + half * half;
    }
    else if (r < half && c < half) {
        return solve(half, r, c);
    }
    else if (r >= half && c < half) {
        return solve(half, r - half, c) + 2 * half * half;
    }
    else if (r >= half && c >= half) {
        return solve(half, r - half, c - half) + 3 * half * half;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> r >> c;
    cout << solve((1 << N), r, c);
}

