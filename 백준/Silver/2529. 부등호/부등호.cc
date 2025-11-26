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

int N;
vector<char> v;
vector<char> p;
vector<int> vis(10, 0);
vector<string> ans;
void solve() {
    if (p.size() == N + 1) {
        string num = "";
        for (int i = 0; i < N + 1; i++) {
            num += p[i];
        }
        ans.push_back(num);
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (vis[i]) continue;
        if (p.size() > 0 && ((v[p.size() - 1] == '<' && p[p.size() - 1] >= (i + '0')) || (v[p.size() - 1] == '>' && p[p.size() - 1] <= (i + '0')))) continue;
        vis[i] = 1;
        p.push_back(i + '0');
        solve();
        p.pop_back();
        vis[i] = 0;
    }
}



int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        v.push_back(c);
    }

    solve();
    cout << ans[ans.size() - 1] << "\n" << ans[0] << "\n";
}