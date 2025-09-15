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

int t[1002];
int dp[32][1002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, W;
	cin >> T >> W;

	for (int i = 1; i <= T; i++) {
		cin >> t[i];
	}

	dp[0][1] = t[1] == 1 ? 1 : 0;

	for (int i = 2; i <= T; i++) {
		dp[0][i] = t[i] == 1 ? dp[0][i - 1] + 1 : dp[0][i - 1];
	}


	for (int i = 1; i <= W; i++) {
		for (int j = 1; j <= T; j++) {
			
			int pos = (i % 2 == 0) ? 1 : 2;
			int eat = (t[j] == pos) ? 1 : 0;

			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1]) + eat;
		}
	}
	int ans = 0;
	for (int i = 0; i <= W; i++) {
		
		if (ans < dp[i][T]) ans = dp[i][T];
		
	}

	//cout << "\n";
	//for (int i = 0; i <= W; i++) {

	//	for (int j = 1; j <= T; j++) {
	//		cout << dp[i][j] << " ";
	//	}
	//	cout << "\n";

	//}


	cout << ans;
}
