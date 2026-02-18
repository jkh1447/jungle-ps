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
int n, k;
vector<int> path;
vector<string> ans;

void dfs(string s, LL hap) { 
    if (hap > n) return;
    if (hap == n) {
        ans.push_back(s);
        return;
    }
    for (int x : {1, 2, 3}) {
        dfs(s + to_string(x), hap + x);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    
    dfs("", 0);
    sort(ans.begin(), ans.end());

    //for (int i = 0; i < ans.size(); i++) {
    //    for (int j = 0; j < ans[i].size()-1; j++) {
    //        cout << ans[i][j] << "+";
    //    }
    //    cout << ans[i][ans[i].size() - 1];
    //    cout << "\n";
    //}
    if (ans.size() < k) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < ans[k-1].size()-1; i++) {
        cout << ans[k - 1][i] << "+";
    }
    cout << ans[k - 1][ans[k - 1].size() - 1];
}