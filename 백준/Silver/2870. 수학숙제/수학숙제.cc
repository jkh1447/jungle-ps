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

bool bigNumberCmp(const string& a, const string& b) {
	if (a.size() != b.size()) return a.size() < b.size();
	return a < b;
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<string> ans;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		bool flag = false;
		string hap = "";
		for (int j = 0; j < s.size(); j++) {
			if (isdigit(s[j])) {
				if (s[j] == '0') {
					if (!flag && j < s.size()-1 && isdigit(s[j+1]) ) {
						continue;
					}

				}

				flag = true;
				hap += s[j];
			}
			else {
				if (flag) {
					ans.push_back(hap);
					flag = false;
					hap = "";
				}
			}
		}
		if (flag) ans.push_back(hap);

	}

	sort(ans.begin(), ans.end(), bigNumberCmp);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}

}
