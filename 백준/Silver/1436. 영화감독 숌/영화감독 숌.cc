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
    
    int N;
    cin >> N;
    vector<int> v;

    int cur = 666;
    while (v.size() != N) {
        string tmp = to_string(cur);
        int cnt = 0;
        bool flag = false;
        for (int i = 0; i < tmp.size() - 1; i++) {
            if (tmp[i] == '6' && tmp[i + 1] == '6') cnt++;
            else cnt = 0;

            if (cnt >= 2) {
                flag = true;
                break;
            }
        }
        if (flag) v.push_back(cur);
        cur++;
    }
    sort(v.begin(), v.end());
    cout << *prev(v.end());
}