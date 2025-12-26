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

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };
vector<LL> primes;
void era() {
    vector<bool> check(500'001, true);
    check[0] = false; check[1] = false;
    for (int i = 2; i * i <= 500'000; i++) {
        if (!check[i]) continue;
        for (int j = i * i; j <= 500'000; j+=i) {
            check[j] = false;
        }
    }

    for (int i = 2; i < 500'001; i++) {
        if (check[i])
            primes.push_back(i);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    era();

    int k;
    cin >> k;

    cout << primes[k - 1];
}
