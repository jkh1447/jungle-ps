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

vector<pair<int, int>> adj[1002];
int INF = 0x7fffffff;
int dist[1001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N;
	cin >> M;

	fill(dist, dist + N + 1, INF);

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
	}
	int s, e;
	cin >> s >> e;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[s] = 0;
	pq.push({ 0, s });

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (dist[cur.Y] != cur.X) continue;
		for (auto nxt : adj[cur.Y]) {
			if (dist[nxt.Y] <= dist[cur.Y] + nxt.X) continue;
			dist[nxt.Y] = dist[cur.Y] + nxt.X;
			pq.push({ dist[nxt.Y], nxt.Y });
		}
	}
	cout << dist[e];
}
