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
	int n;
	cin >> n;
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end(), [](string& a, string& b) {
		if (a.size() != b.size()) {
			return a.size() < b.size();
		}
		else if (a.size() == b.size()) {
			int hap1 = 0, hap2 = 0;
			for (int i = 0; i < a.size(); i++) {
				if ('0' <= a[i] && a[i] <= '9') hap1 += a[i] - '0';
			}
			for (int i = 0; i < b.size(); i++) {
				if ('0' <= b[i] && b[i] <= '9') hap2 += b[i] - '0';
			}
			if (hap1 != hap2) return hap1 < hap2;
			else return a < b;
		}
		
		});

	for (int i = 0; i < n; i++) cout << v[i] << "\n";
}
