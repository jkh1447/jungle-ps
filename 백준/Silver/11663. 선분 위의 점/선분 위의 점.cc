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
    int n, m;
    cin >> n >> m;
    vector<int> points(n);
    vector<pair<int, int>> lines;
    for (int i = 0; i < n; i++) cin >> points[i];
    sort(points.begin(), points.end());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int s, e;
        int st = 0, en = n;
        while (st < en) {
            int mid = (st + en) / 2;
            if (a <= points[mid]) en = mid;
            else st = mid + 1;
        }
        s = st;

        st = 0; en = n;
        while (st < en) {
            int mid = (st + en) / 2;
            if (b < points[mid]) en = mid;
            else st = mid + 1;
        }
        e = st;

        cout << e - s << "\n";
    }
    

}