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

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

//int dx[4] = { -1, 0, 1, 0 };
//int dy[4] = { 0, 1, 0, -1 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };

//int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
//int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

using namespace std;

int a[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        string W;
        int K;
        cin >> W;
        cin >> K;
        int three = W.size() + 2, four = 0;

        if (K == 1) {
            cout << "1 1\n";
            continue;
        }
        
        vector<int> pos[26];
        for (int i = 0; i < W.size(); i++){
            pos[W[i] - 'a'].push_back(i);
        }

        for (int i = 0; i < 26; i++) {
            if ((int)pos[i].size() < K) continue;
            for (int j = 0; j < pos[i].size() - K + 1; j++) {
                
                int len = pos[i][j + K - 1] - pos[i][j] + 1;
                three = min(three, len);
                four = max(four, len);
            }
        }

        if (four == 0 || three == W.size() + 2) cout << "-1\n";
        else cout << three << " " << four << "\n";
    }

}