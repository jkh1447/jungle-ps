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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> dice(6, 0);
    LL n;
    cin >> n;
    for (int i = 0; i < 6; i++) cin >> dice[i];


    if (n == 1) {
        sort(dice.begin(), dice.end());
        int res = 0;    
        for (int i = 0; i < 5; i++) res += dice[i];
        cout << res;
        return 0;
    }


    LL three = 1e20;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (j == i) continue;
            if ((i == 0 && j == 5) || (i == 1 && j == 4) || (i == 2 && j == 3) || (i == 3 && j == 2) ||
                (i == 4 && j == 1) || (i == 5 && j == 0)) continue;


            for (int k = 0; k < 6; k++) {
                if (k == i || k == j) continue;
                if ((i == 0 && k == 5) || (i == 1 && k == 4) || (i == 2 && k == 3) || (i == 3 && k == 2) ||
                    (i == 4 && k == 1) || (i == 5 && k == 0)) continue;
                if ((j == 0 && k == 5) || (j == 1 && k == 4) || (j == 2 && k == 3) || (j == 3 && k == 2) ||
                    (j == 4 && k == 1) || (j == 5 && k == 0)) continue;
                three = min(three, (LL)dice[i] + dice[j] + dice[k]);
            }
        }
    }
    LL two = 1e20;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (i == j) continue;
            if ((i == 0 && j == 5) || (i == 1 && j == 4) || (i == 2 && j == 3) || (i == 3 && j == 2) ||
                (i == 4 && j == 1) || (i == 5 && j == 0)) continue; 
            two = min(two, (LL)dice[i] + dice[j]);
        }
    }

    LL one = 1e20;
    for (int i = 0; i < 6; i++) one = min(one, (LL)dice[i]);

    cout << three * 4 + two * (4 + 8 * (n - 2)) + one * ((LL)(n - 2) * 4 + (LL)(n - 2) * (n - 2) * 5);
}