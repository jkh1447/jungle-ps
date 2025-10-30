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

int arr[300'002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    if (N == 0) cout << 0;
    else {
        for (int i = 0; i < N; i++) cin >> arr[i];

        sort(arr, arr + N);
        int maxval = arr[N - 1], minval = arr[0];
        int julsa = round((N * 0.15));

        int s = julsa, e = N - 1 - julsa;


        double hap = 0;
        for (int i = s; i <= e; i++) hap += arr[i];

        int ans = round(hap / (N - 2 * julsa));

        cout << ans;

    }

}