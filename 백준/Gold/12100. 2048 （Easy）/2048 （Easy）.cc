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

int board1[21][21];
int board2[21][21];

int n;

void rotate() {
	int tmp[21][21];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp[n - j - 1][i] = board2[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board2[i][j] = tmp[i][j];
		}
	}
}

void tilt(int dir ) {
	while (dir--) rotate();

	for (int i = 0; i < n; i++) {
		vector<int> tmp(n, 0);
		int cur = 0;
		for (int j = 0; j < n; j++) {
			if (board2[i][j] == 0) continue;
			if (tmp[cur] == 0) tmp[cur] = board2[i][j];
			else if (tmp[cur] == board2[i][j]) {
				tmp[cur++] *= 2;
			}
			else {
				tmp[++cur] = board2[i][j];
			}
		}

		for (int j = 0; j < n; j++) {
			board2[i][j] = tmp[j];
		}
	}
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
    
	int ans = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board1[i][j];
		}
	}

	for (int t = 0; t < (1 << 10); t++) {
		int cur = t;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				board2[i][j] = board1[i][j];
			}
		}

		for (int dir = 0; dir < 5; dir++) {
			int digit = cur % 4;
			cur = cur / 4;

			tilt(digit);
		}

		int max_val = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (max_val < board2[i][j]) max_val = board2[i][j];
			}
		}
		 
		ans = max(max_val, ans);
	}

	cout << ans;

}
