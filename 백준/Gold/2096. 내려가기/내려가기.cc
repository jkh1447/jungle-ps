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

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };

int arr[100002][3];
int maxdp[2][3];
int mindp[2][3];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    maxdp[0][0] = arr[0][0];
    maxdp[0][1] = arr[0][1];
    maxdp[0][2] = arr[0][2];
    mindp[0][0] = arr[0][0];
    mindp[0][1] = arr[0][1];
    mindp[0][2] = arr[0][2];
    
    for (int i = 1; i < N; i++) {
        maxdp[i%2][0] = arr[i][0] + max(maxdp[1 - i%2][0], maxdp[1 - i % 2][1]);
        maxdp[i % 2][1] = arr[i][1] + max(maxdp[1 - i % 2][0], max(maxdp[1 - i % 2][1], maxdp[1 - i % 2][2]));
        maxdp[i % 2][2] = arr[i][2] + max(maxdp[1 - i % 2][1], maxdp[1 - i % 2][2]);

        mindp[i % 2][0] = arr[i][0] + min(mindp[1 - i % 2][0], mindp[1 - i % 2][1]);
        mindp[i % 2][1] = arr[i][1] + min(mindp[1 - i % 2][0], min(mindp[1 - i % 2][1], mindp[1 - i % 2][2]));
        mindp[i % 2][2] = arr[i][2] + min(mindp[1 - i % 2][1], mindp[1 - i % 2][2]);
    }


    cout << *max_element(maxdp[1-N % 2], maxdp[1 - N % 2] + 3) << " " << *min_element(mindp[1 - N % 2], mindp[1 - N % 2] + 3);
}