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

bool bs(int n, int t) {
	int st = 0;
	int en = n - 1;

	while (st <= en) {
		int mid = (st + en) / 2;

		if (arr[mid] > t) en = mid - 1;
		else if (arr[mid] < t) st = mid + 1;
		else return true;
	}

	return false;
}



int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);

	cin >> M;

	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;


		if (bs(N, num)) cout << 1 << " ";
		else cout << 0 << " ";


	}

}