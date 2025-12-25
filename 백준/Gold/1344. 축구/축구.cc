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
double combi(int n, int r) {
    double result = 1;
    for (int i = 0; i < r; i++) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b;
    cin >> a >> b;
    a /= 100;
    b /= 100;
    
    double pa = 0, pb = 0;

    int notPrime[] = { 0, 1, 4, 6, 8, 9, 10, 12, 14, 15, 16, 18 };

    for (int x : notPrime) {
        pa += combi(18, x) * pow(a, x) * pow(1-a, 18 - x);
        pb += combi(18, x) * pow(b, x) * pow(1-b, 18 - x);
    }

    //int primes[] = { 2, 3, 5, 7, 11 , 13, 17 };
    //for (int x : primes) {
    //    pa += combi(18, x) * pow(a, x) * pow(1 - a, 18 - x);
    //    pb += combi(18, x) * pow(b, x) * pow(1 - b, 18 - x);
    //}

    cout << fixed << setprecision(7) <<  1 - pa * pb;
    // cout << fixed << setprecision(7) << 1 - (1-pa) * (1-pb);
    
}
