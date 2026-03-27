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
//int dx[4] = { 1, 0, -1, 0 };
//int dy[4] = { 0, 1, 0, -1 };

//int dx[4] = { -1, 0, 1, 0 };
//int dy[4] = { 0, 1, 0, -1 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };

//int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
//int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int N, M;
void solve(vector<int>& v, int s, vector<int>& ans) {
    if (ans.size() == M) {
        for (int nxt : ans) cout << nxt << " ";
        cout << "\n";
        return;
    }
    for (int i = s; i < v.size(); i++) {
        ans.push_back(v[i]);
        solve(v, i + 1, ans);
        ans.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    cin >> N >> M;
    vector<int> v(N, 0);
    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());
    vector<int> ans;
    solve(v, 0, ans);
}

