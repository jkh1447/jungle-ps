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

vector<int> pns;
void era() {
    vector<bool> check(1'000'001, true);
    check[0] = false;
    check[1] = false;
    for (int i = 2; i * i <= 1000000; i++) {
        if (!check[i]) continue;
        for (int j = i; i*j <= 1000000; j++) {
            check[i * j] = false;
        }
    }
    for (int i = 1; i <= 1000000; i++) {
        if (check[i])
            pns.push_back(i);
    }
}

int getPrime(int A) {
    int ans = 0;
    int i = 0;
    while (pns[i] <= A) {
        if (A % pns[i] == 0) ans = pns[i];
        i++;
    }

    return ans;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int gcd2(vector<int>& v) {
    int g = v[0];
    for (int i = 1; i < v.size(); i++) {
        g = gcd(g, v[i]);
        if (g == 1) break;
    }
    return g;
}

int main() { 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    
    unordered_map<int, long long> total;
    vector<unordered_map<int, int>> fact(n);

    for (int i = 0; i < n; i++) {
        int x = v[i];
        for (int p = 2; p * p <= x; p++) {
            while (x % p == 0) {
                fact[i][p]++;
                total[p]++;
                x /= p;
            }
        }
        if (x > 1) {
            fact[i][x]++;
            total[x]++;
        }
    }

    long long gcd_val = 1;
    unordered_map<int, long long> target;

    for (auto& it : total) {
        int p = it.X;
        long long cnt = it.Y / n;
        if (cnt > 0) {
            target[p] = cnt;
            for (int i = 0; i < cnt; i++) gcd_val *= p;
        }
    }

    long long ops = 0;
    for (int i = 0; i < n; i++) {
        for (auto& it : target) {
            int p = it.first;
            LL need = it.second;
            LL have = fact[i][p];
            if (have < need)
                ops += (need - have);
        }
    }

    cout << gcd_val << " " << ops;
}
