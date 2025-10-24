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
    int N, M;
    cin >> N >> M;

    map<string, int> m;

    for(int i=0; i<N+M; i++) {
        string name;
        cin >> name;
        m[name]++;
    }
    vector<string> v;
    for (auto nxt : m) {
        if (nxt.second == 2) v.push_back(nxt.first);
    }

    cout << v.size() << "\n";
    for (string s : v) cout << s << "\n";
   
}