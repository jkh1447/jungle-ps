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


int board[102][102];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		board[x][y] = 4;
	}

	int L;
	cin >> L;
	
	deque<pair<int, int>> dq; // 앞이 꼬리 뒤가 머리
	dq.push_back({ 1, 1, });
	board[1][1] = 1;
	int dir = 0;
	int ans = 0;
	bool flag = false;

	queue<pair<int, char>> q;
	for (int i = 0; i < L; i++) {
		int x;
		char t;
		cin >> x >> t;
		q.push({ x, t });
	}

	while (true) {
		auto cur = dq.back();

		int nx = cur.X + dx[dir];
		int ny = cur.Y + dy[dir];


		if (find(dq.begin(), dq.end(), make_pair(nx, ny)) != dq.end()) {
			ans++;

			break;
		}
		if (nx < 1 || nx > N || ny < 1 || ny > N) {
			ans++;

			break;
		}

		if (board[nx][ny] == 4) {
			dq.push_back({ nx, ny });
			board[nx][ny] = 1;
		}
		else {
			pair<int, int> tmp = dq.front();
			dq.pop_front();
			dq.push_back({ nx, ny });
			board[nx][ny] = 1;
			board[tmp.X][tmp.Y] = 0;
		}
		ans++;
		//cout << "\n";
		//for (int j = 1; j <= N; j++) {
		//	for (int k = 1; k <= N; k++) {
		//		cout << board[j][k] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";

		if (q.empty()) continue;
		auto tmp = q.front();
		if (ans == tmp.X) {
			q.pop();
			if (tmp.Y == 'D') {
				dir = (dir + 1) % 4;

			}
			else {
				dir = (dir - 1 + 4) % 4;
			}
		}

	}

	

	cout << ans;

}
