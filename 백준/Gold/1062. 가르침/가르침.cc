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
vector<int> nouns;
int n, k;
int ans = 0;
void dfs(int s, int mask, int cnt) {
    if (cnt == k - 5) {
        int count = 0;
        for (int i = 0; i < nouns.size(); i++) {
            if ((nouns[i] & mask) == nouns[i]) count++;
        }
        ans = max(ans, count);
        return;
    }

    for (int i = s; i < 26; i++) {
        if (mask & (1 << i)) continue;
        mask |= (1 << i);
        dfs(i + 1, mask, cnt+1);
        mask &= ~(1 << i);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int pmask = 0;
    pmask |= (1 << ('a' - 'a'));
    pmask |= (1 << ('n' - 'a'));
    pmask |= (1 << ('t' - 'a'));
    pmask |= (1 << ('i' - 'a'));
    pmask |= (1 << ('c' - 'a'));
    cin >> n >> k;
    if (k < 5) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int bits = 0;
        for (int j = 0; j < s.size(); j++) {
            bits |= (1 << (s[j] - 'a'));
        }
        nouns.push_back(bits);
    }
    dfs(0, pmask, 0);
    cout << ans;
}