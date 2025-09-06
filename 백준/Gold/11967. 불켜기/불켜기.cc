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

vector<pair<int, int>> board[102][102];
int isOn[102][102];
int visited[102][102];
int isOk[102][102];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		board[x][y].push_back({ a, b });
	}
	int ans = 0;
	queue<pair<int, int>> q;
	q.push({ 1, 1 });
	ans++;
	visited[1][1] = 1;
	isOn[1][1] = 1;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		
		if (!isOk[cur.X][cur.Y]) {
			auto lights = board[cur.X][cur.Y];
			for (int i = 0; i < board[cur.X][cur.Y].size(); i++) {
				
				if (isOn[lights[i].X][lights[i].Y]) continue;
				if (lights[i].X <= 0 || lights[i].X > N ||
					lights[i].Y <= 0 || lights[i].Y > N) continue;
				isOn[lights[i].X][lights[i].Y] = 1;
				ans++;
				for (int dir = 0; dir < 4; dir++) {
					int nx = lights[i].X + dx[dir];
					int ny = lights[i].Y + dy[dir];
					if (nx <= 0 || nx > N || ny <= 0 || ny > N) continue;

					if (visited[nx][ny]) {

						q.push({ nx, ny });
					}
				
				}
			}
			isOk[cur.X][cur.Y] = 1;

		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx <= 0 || nx > N || ny <= 0 || ny > N) continue;
			if (!isOn[nx][ny] || visited[nx][ny]) continue;
			visited[nx][ny] = 1;
			q.push({ nx, ny });
		}
		

	}
	cout << ans;
}
