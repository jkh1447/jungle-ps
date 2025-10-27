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

int dist[10001];
char path[10001];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;

    while (T--) {
        fill(dist, dist + 10001, -1);
        int a, b;
        cin >> a >> b;
        queue<int> q;
        q.push(a);
        dist[a] = 0;

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            // cout << cur << "=> ";
            if (cur == b) break;

            int D = (cur * 2) % 10000;
            if (dist[D] < 0 && D >= 0 && D < 10000) {
                dist[D] = cur;
                path[D] = 'D';
                q.push(D);
            }

            int S = cur - 1;
            if (S < 0) S = 9999;
            if (S >= 0 && S < 10000 && dist[S] < 0) {
                dist[S] = cur;
                path[S] = 'S';
                q.push(S);
            }

            int L = (cur / 1000) + (cur % 1000) * 10;
      
            if (L >= 0 && L < 10000 && dist[L] < 0) {
                dist[L] = cur;
                path[L] = 'L';
                q.push(L);
            }

            int R = (cur % 10) * 1000 + (cur / 10);
            if (R >= 0 && R < 10000 && dist[R] < 0) {
                dist[R] = cur;
                path[R] = 'R';
                q.push(R);
            }
        }
        
        vector<char> ans;

        int cur = b;
        while (cur != a) {
            ans.push_back(path[cur]);
            cur = dist[cur];
        }

        for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
        cout << "\n";



    }
}