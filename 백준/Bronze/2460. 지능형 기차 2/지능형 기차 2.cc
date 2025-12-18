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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cur = 0;
    int maxval = 0;
    for (int i = 0; i < 10; i++) {
        int in, out;
        cin >> out >> in;
        cur -= out;
        maxval = max(maxval, cur);
        cur += in;
        maxval = max(maxval, cur);
    }
    cout << maxval;
}
