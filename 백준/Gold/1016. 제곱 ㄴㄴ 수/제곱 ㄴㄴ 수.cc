#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>
#include <unordered_map>
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


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long long a, b;
	cin >> a >> b;

	vector<bool> v(b-a+1, true);
	for (long long i = 2; i * i <= b; i++) {
		long long s = i * i;
		for (long long j = (s+a-1) / s * s; j <= b; j += s) {
			v[j - a] = false;
		}
	}

	long long ans = 0;
	for (long long i = 0; i < b-a+1; i++) {
		if (v[i]) ans++;
	}
	cout << ans;

}
