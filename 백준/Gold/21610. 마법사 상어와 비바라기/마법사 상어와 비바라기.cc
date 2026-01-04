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

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };

int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int board[52][52];
int cloud[52][52];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    vector<pair<int, int>> move(m);
    for (int i = 0; i < m; i++) {
        int d, s;
        cin >> d >> s;
        move[i] = { d, s };
    }
    vector<pair<int, int>> clouds;
    clouds.push_back({ n - 2, 0 });
    clouds.push_back({ n - 2, 1 });
    clouds.push_back({ n - 1, 0 });
    clouds.push_back({ n - 1, 1 });


    for (int q = 0; q < m; q++) {
        for (int i = 0; i < n; i++)
            fill(cloud[i], cloud[i] + n, 0);

        int dir = move[q].X - 1;
        int dist = move[q].Y;

        for (int i = 0; i < clouds.size(); i++) {
            int x = clouds[i].X, y = clouds[i].Y;
            int nx = (x + dx[dir] * dist % n + n) % n;
            int ny = (y + dy[dir] * dist % n + n) % n; 

            clouds[i].X = nx; clouds[i].Y = ny;
        }
        
        for (int i = 0; i < clouds.size(); i++) {
            int x = clouds[i].X, y = clouds[i].Y;
            board[x][y]++;
            cloud[x][y] = 1;
        }

        for (int i = 0; i < clouds.size(); i++) {
            int x = clouds[i].X, y = clouds[i].Y;
            int dw = 0;
            for (int d = 1; d < 8; d += 2) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (board[nx][ny] != 0) dw++;
            }
            board[x][y] += dw;
        }
        clouds.clear();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cloud[i][j] == 1) continue;
                if (board[i][j] >= 2) {
                    board[i][j] -= 2;
                    clouds.push_back({ i, j });
                }
            }
        }

    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += board[i][j];
        }
    }
    cout << ans;
}