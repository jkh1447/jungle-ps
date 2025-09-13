#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>
using namespace std;

#define X first
#define Y second

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };

int board[102][102];
int dist[102][102];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			board[i][j] = s[j] - '0';
		}
	}

	deque<pair<int, int>> dq;
	dq.push_back({ 0, 0 });
	dist[0][0] = 1;

	while (!dq.empty()) {
		auto cur = dq.front();
		dq.pop_front();

		if (cur.X == N - 1 && cur.Y == M - 1) {
			cout << dist[N - 1][M - 1] - 1;
			return 0;
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (dist[nx][ny] > 0) continue;
			if (board[nx][ny] == 0) {
				dist[nx][ny] = dist[cur.X][cur.Y];
				dq.push_front({ nx, ny });
			}
			if (board[nx][ny] == 1) {
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				dq.push_back({ nx, ny });
			}

		}
	}


}
