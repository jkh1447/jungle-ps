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


char board[20][10];
bool visited[20][10];
int ans;

bool bfs(int x, int y) {
	bool flag = false;
	char c = board[x][y];
	visited[x][y] = true;
	queue<pair<int, int>> q;
	q.push({ x, y });
	vector<pair<int, int>> cand;
	int cnt = 0;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		cand.push_back({ cur.X, cur.Y });
		cnt++;
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
			if (visited[nx][ny] || board[nx][ny] == '.' || board[nx][ny] != c) continue;
			visited[nx][ny] = true;
			q.push({ nx, ny });
		}
	}
	
	if (cnt >= 4) {
		flag = true;
		for (auto nxt : cand) {
			board[nxt.X][nxt.Y] = '.';
		}

	}
	return flag;
}

void down() {

	for (int i = 0; i < 6; i++) {
		vector<char> t;
		for (int j = 0; j < 12; j++) {
			if (board[j][i] != '.') {
				t.push_back(board[j][i]);
				board[j][i] = '.';
			}
		}
		int idx = 11;
		while (!t.empty() && idx > -1) {
			board[idx][i] = t[t.size()-1];
			t.pop_back();
			idx--;
		}
	}
}

void clear() {
	bool flag = false;

	while (true) {

		for (int k = 0; k < 12; k++) {
			fill(visited[k], visited[k] + 6, false);
		}

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (visited[i][j] || board[i][j] == '.') continue;

				if (bfs(i, j)) flag = true;
			
			}
		}


		down();



		if (!flag) {
			break;
		}
		ans++;
		flag = false;

	}
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for (int i = 0; i < 12; i++) {
		
		for (int j = 0; j < 6; j++) {
			cin >> board[i][j];
		}
	}
	
	clear();


	cout << ans;
}
