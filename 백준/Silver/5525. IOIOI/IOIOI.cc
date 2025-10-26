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
    string S;
    cin >> N >> M >> S;
    int ans = 0;
    int cnt = 0;
    for (int i = 1; i < M-1; i++) {
        if (S[i - 1] == 'I' && S[i] == 'O' && S[i + 1] == 'I') {
            cnt++;
            if (cnt == N) {
                ans++;
                cnt--;
            }
            i++;
        }
        else cnt = 0;

        
    }

    cout << ans;
}