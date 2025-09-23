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
#include <cctype>
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

	int n;
	cin >> n;
	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}
	sort(v.begin(), v.end());
	
	long long ans = 0;
	
	int l = v[0].X, r = v[0].Y;
	for (int i = 1; i < v.size(); i++) {
		int a, b;
		tie(a, b) = v[i];

		if (r <= a) {
			ans += r - l;
			l = a, r = b;
		}
		else if (a < r && r <= b) {
			r = b;
		}
		else if (l <= a && b <= r) continue;
	}

	cout << ans + (r - l);
}

