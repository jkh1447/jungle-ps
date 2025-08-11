#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };

vector<int> adj[600];

int vis[600];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;

	cin >> n;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vis[1] = 1;
	queue<int> q;
	q.push(1);
	int ans = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int nxt : adj[cur]) {
			if (vis[nxt]) continue;
			vis[nxt] = vis[cur] + 1;
			if (vis[nxt] <= 3) ans++;
			q.push(nxt);
		}
	}
	cout << ans;
}