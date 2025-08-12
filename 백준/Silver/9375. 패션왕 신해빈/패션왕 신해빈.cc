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
	
	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int n;
		cin >> n;
		unordered_map<string, vector<string>> clst;
		for (int i = 0; i < n; i++) {
			string name, type;

			cin >> name >> type;
			clst[type].push_back(name);
		}
		long long ans = 1;
		for (auto cur = clst.begin(); cur != clst.end(); cur++) {
			ans *= ((*cur).Y.size() + 1);
		}
		
		cout << ans - 1 << "\n";
	}
	

}