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
	priority_queue<int, vector<int>> maxh;
	priority_queue<int, vector<int>, greater<int>> minh;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;

		if (maxh.empty() && minh.empty()) maxh.push(tmp);
		else if (maxh.top() <= tmp) minh.push(tmp);
		else maxh.push(tmp);

		if (maxh.size() < minh.size()) {
			maxh.push(minh.top());
			minh.pop();
		}
		else if (maxh.size() > minh.size() + 1) {
			minh.push(maxh.top());
			maxh.pop();
		}

		cout << maxh.top() << "\n";
	}


}

