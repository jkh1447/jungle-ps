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

int s[21];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int M;
    cin >> M;
    while (M--) {
        string q;
        cin >> q;
        
        string n;
        if (q == "add") {
            cin >> n;
            s[stoi(n)] = 1;
        }
        else if (q == "check") {
            cin >> n;
            if (s[stoi(n)] > 0) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if (q == "remove") {
            cin >> n;
            s[stoi(n)] = 0;
        }
        else if (q == "toggle") {
            cin >> n;
            s[stoi(n)] = 1 - s[stoi(n)];
        }
        else if (q == "all") {
            for (int i = 1; i <= 20; i++) s[i] = 1;
        }
        else if (q == "empty") {
            for (int i = 1; i <= 20; i++) s[i] = 0;
        }
        
    }
}