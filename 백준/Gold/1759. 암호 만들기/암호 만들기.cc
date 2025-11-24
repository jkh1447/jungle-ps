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
int l, c;
vector<char> v;
vector<int> vis;
void func(vector<char> &p, int s) {

    if (p.size() == l) {

        int jaeum = 0, moeum = 0;
        for (int i = 0; i < l; i++) {
            if (p[i] == 'a' || p[i] == 'e' || p[i] == 'i' || p[i] == 'o' || p[i] == 'u') {
                moeum++;
            }
            else jaeum++;
        }

        if (moeum >= 1 && jaeum >= 2) {
            for (int i = 0; i < l; i++) cout << p[i];
            cout << "\n";
        }

        return;
    }

    for (int i = s; i < c; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        p.push_back(v[i]);
        func(p, i + 1);
        p.pop_back();
        vis[i] = 0;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    

    cin >> l >> c;
    v.resize(c);
    vis.resize(c, 0);
    for (int i = 0; i < c; i++) cin >> v[i];
    sort(v.begin(), v.end());
    vector<char> path;
    func(path, 0);
}