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

int cost[21][21];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int answer = 1e9;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> cost[i][j];
    }

    for (int i = 1; i < (1 << N)-1; i++) {
        int cur = i;
        vector<int> t1;
        vector<int> t2;
        for (int j = 0; j < N; j++) {
            int digit = cur % 2;

            if (digit == 1) {
                t1.push_back(j);
            }
            else t2.push_back(j);

            cur = cur / 2;
        }


        int hap1 = 0;
        int hap2 = 0;
        for (int j = 0; j < t1.size(); j++) {
            for (int k = j + 1; k < t1.size(); k++) {
                hap1 += cost[t1[j]][t1[k]];
                hap1 += cost[t1[k]][t1[j]];
            }
        }

        for (int j = 0; j < t2.size(); j++) {
            for (int k = j + 1; k < t2.size(); k++) {
                hap2 += cost[t2[j]][t2[k]];
                hap2 += cost[t2[k]][t2[j]];
            }
        } 

        
        answer = min(answer, abs(hap1 - hap2));
    }

    cout << answer;
}