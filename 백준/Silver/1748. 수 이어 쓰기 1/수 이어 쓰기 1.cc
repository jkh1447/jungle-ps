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

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int cur = n;
    int digitN = 0;
    while (cur != 0) {
        cur /= 10;
        digitN++;
    }
    int ans = 0;
    int start = 1;
    for (int i = 0; i < digitN-1; i++) {
        ans += 9 * start * (i + 1);
        start *= 10;
    }
    ans += digitN * (n - start + 1);

    cout << ans;
}