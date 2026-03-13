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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        map<double, vector<string>, greater<double>> m;
        for (int i = 0; i < n; i++) {
            string name;
            double h;
            cin >> name >> h;
            m[h].push_back(name);
        }
        for (auto nxt : m) {
            for (int i = 0; i < nxt.Y.size(); i++) {
                cout << nxt.Y[i] << " ";
            }
            break;
        }
        cout << "\n";
    }
}

