#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };

int arr[500002];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	

	int n, m;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr[i] = tmp;
	}

	sort(arr, arr + n);

	cin >> m;

	for (int i = 0; i < m; i++) {
		int upperIdx;
		int lowerIdx;
		int target;
		cin >> target;

		int st = 0;
		int en = n;


		while (st < en) {
			int mid = (st + en) / 2;

			if (arr[mid] > target) {
				en = mid;
			}
			else {
				st = mid + 1;
			}
		}
		upperIdx = st;

		st = 0;
		en = n;
		while (st < en) {
			int mid = (st + en) / 2;

			if (arr[mid] >= target) {
				en = mid;
			}
			else {
				st = mid + 1;
			}
		}

		lowerIdx = st;

		cout << upperIdx - lowerIdx << " ";
	}


}