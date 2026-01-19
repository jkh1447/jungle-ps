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
int n, m, r;

int board[101][101];

void flip() {
    int tmp[101][101];
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            tmp[i][j] = board[n - i - 1][j];
        }
    }
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            board[i][j] = tmp[i][j];
}

void leftright() {
    int tmp[101][101];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tmp[i][j] = board[i][m - j - 1];
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            board[i][j] = tmp[i][j];
}

void rotate(int dir) {
    int tmp[101][101];
    if (dir == 1) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tmp[i][j] = board[j][m - i - 1];
            }
        }
    }
    else if (dir == 0) { // right
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tmp[i][j] = board[n-j-1][i];
            }
        }
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = tmp[i][j];
    swap(n, m);
}

void five() {
    int tmp[101][101];

    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < m/2; j++) {
            tmp[i][m/2+j] = board[i][j];
        }
    }

    for (int i = 0; i < n/2; i++) {
        for (int j = m / 2; j < m; j++) {
            tmp[n / 2 + i][j] = board[i][j];
        }
    }

    for (int i = n / 2; i < n; i++) {
        for (int j = m / 2; j < m; j++) {
            tmp[i][j - m / 2] = board[i][j];
        }
    }

    for (int i = n / 2; i < n; i++) {
        for (int j = 0; j < m / 2; j++) {
            tmp[i - n / 2][j] = board[i][j];
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            board[i][j] = tmp[i][j];

}

void six() {
    for (int i = 0; i < 3; i++) five();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    while (r--) {
        int q;
        cin >> q;

        if (q == 1) flip();
        else if (q == 2) leftright();
        else if (q == 3) rotate(0);
        else if (q == 4) rotate(1);
        else if (q == 5) five();
        else if (q == 6) six();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";

        }
        cout << "\n";
    }
}