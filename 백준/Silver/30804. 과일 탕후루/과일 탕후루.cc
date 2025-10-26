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

int k[200'002];
int f[200'002];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }
    int ans = 0;
    int st = 0;
    int kn = 0;
    for (int en = 0; en < n; en++) {
        k[f[en]]++;
        if (k[f[en]] == 1) kn++;


        while (kn > 2) {
            k[f[st]]--;
            if (k[f[st]] == 0) kn--;
            st++;
        }
        
        ans = max(ans, en - st + 1);

    }
    cout << ans;
}