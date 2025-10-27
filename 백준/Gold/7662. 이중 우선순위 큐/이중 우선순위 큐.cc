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

bool vis[1000001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;

    while (T--) {

        priority_queue<pair<int, int>> maxheap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;

        int n;
        cin >> n;
        

        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;

            if (c == 'I') {
                int tmp;
                cin >> tmp;
                maxheap.push({ tmp, i });
                minheap.push({ tmp, i });
            }
            else if (c == 'D') {
                int tmp;
                cin >> tmp;

                if (tmp == 1) {
                    if (maxheap.empty()) continue;
                    while (!maxheap.empty() && vis[maxheap.top().second]) {
                        maxheap.pop();
                    }
                    if (!maxheap.empty()) {
                        vis[maxheap.top().second] = true;
                        maxheap.pop();

                    }
                }
                else {
                    if (minheap.empty()) continue;
                    while (!minheap.empty() && vis[minheap.top().second]) {
                        minheap.pop();
                    }
                    if (!minheap.empty()) {
                        vis[minheap.top().second] = true;
                        minheap.pop();

                    }
                    
                }
            }
        }

        while (!maxheap.empty() && vis[maxheap.top().second]) {
            maxheap.pop();
        }
        while (!minheap.empty() && vis[minheap.top().second]) {
            minheap.pop();
        }

        if (maxheap.empty() || minheap.empty()) cout << "EMPTY\n";
        else {
            cout << maxheap.top().first << " " << minheap.top().first << "\n";
        }

        fill(vis, vis + 1000001, false);
    }
}