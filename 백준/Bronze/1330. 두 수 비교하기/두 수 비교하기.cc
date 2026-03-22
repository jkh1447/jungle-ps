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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a;
    cin >> b;
    if (a > b) cout << ">";
    if (a < b) cout << "<";
    if (a==b) cout << "==";

}

