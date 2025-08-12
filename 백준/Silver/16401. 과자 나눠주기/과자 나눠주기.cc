#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };

int snack[1000003];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int M, N;

	cin >> M >> N;

	int max_val = 0;

	for (int i = 0; i < N; i++) {
		cin >> snack[i];
		if (max_val < snack[i]) max_val = snack[i];

	}


	int st = 1;
	int en = max_val;

	long long ans = 0;

	while (st <= en) {
		int mid = (st + en) / 2;
		int hap = 0;
		for (int i = 0; i < N; i++) {
			if (snack[i] >= mid) hap += snack[i] / mid;
		}

		if (hap >= M) {
			ans = mid;
			st = mid + 1;
		}
		else {
			en = mid - 1;
		}

	}

	cout << ans;

}