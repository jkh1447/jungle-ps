#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };

int arr[1'000'002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++) cin >> arr[i];


	int ans = 0;
	int cnt = 0;
	int l = 0;

	for (int r = 0; r < N; r++) {
		if (arr[r] % 2 != 0) cnt++;

		while (cnt > K) {
			if (arr[l] % 2 != 0) cnt--;
			l++;
		}

		ans = max(ans, r - l + 1 - cnt);
	}

	cout << ans;
}