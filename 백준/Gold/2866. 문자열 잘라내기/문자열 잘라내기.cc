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

	int n, m;
	cin >> n >> m;
	vector<vector<char>> v(n);

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) v[i].push_back(s[j]);
	}


	int st = 0;
	int en = n;
	int ans = 0;
	bool flag = false;

	while (st <= en) {
		int mid = (st + en) / 2;
		set<string> se;
		for (int j = 0; j < m; j++) {
			string s;
			for (int i = mid; i < n; i++) {
				s += v[i][j];
			}

			se.insert(s);
		}
		if (se.size() == m) {
			st = mid + 1;
			ans = mid;
			flag = true;
		}
		else en = mid - 1;

	}

	cout << ans;


}
