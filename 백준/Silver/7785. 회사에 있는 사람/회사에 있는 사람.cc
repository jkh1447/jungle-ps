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

	unordered_map<string, string> um;

	for (int i = 0; i < n; i++) {
		string name, status;
		cin >> name >> status;

		um[name] = status;

	}

	vector<string> s;

	for (auto pair : um) {
		if (pair.Y == "leave") continue;
		s.push_back(pair.X);
	}

	sort(s.begin(), s.end(), greater<string>());
	for (auto x : s) cout << x << "\n";
}