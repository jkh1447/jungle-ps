#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };

int d[105][105];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);


	int n, m;
	cin >> n;
	cin >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = 0x3f3f3f3f;
		}
	}

	for (int i = 1; i <= n; i++) {
		d[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		if (d[x][y] > c)
			d[x][y] = c;

	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == 0x3f3f3f3f) cout << 0 << " ";
			else cout << d[i][j] << " ";
		}
		cout << "\n";
	}

}