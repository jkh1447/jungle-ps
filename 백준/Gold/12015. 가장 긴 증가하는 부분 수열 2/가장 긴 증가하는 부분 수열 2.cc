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
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a[i] = tmp;
    }
    vector<int> lis;

    for (int x : a) {
        int st = 0;
        int en = lis.size();
        while (st < en) {
            int mid = (st + en) / 2;

            if (lis[mid] >= x) {
                en = mid;
            }
            else {
                st = mid + 1;
            }
        }
        if (st == lis.size()) lis.push_back(x);
        else {
            lis[st] = x;
        }
    }
    cout << lis.size();


}