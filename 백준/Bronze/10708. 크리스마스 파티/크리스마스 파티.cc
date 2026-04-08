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



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> score(N+1, 0);
    int M;
    cin >> M;
    vector<int> t(M+1);
    for (int i = 1; i <= M; i++) cin >> t[i];
    for (int i = 1; i <= M; i++) {
        vector<int> p(N+1);
        for (int j = 1; j <= N; j++) {
            cin >> p[j];
        }
        int cnt = 0;
        for (int j = 1; j <= N; j++) {
            if (t[i] == j) score[j]++;
            else if (t[i] == p[j]) {
                score[j]++;
                cnt++;
            }
        }

        score[t[i]] += N - cnt - 1;
    }

    for (int i = 1; i <= N; i++) {
        cout << score[i] << "\n";
    }
}