#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };


int a[500003];
int b[500003];

bool bs(int n, int t) {
	int st = 0;
	int en = n - 1;

	while (st <= en) {
		int mid = (st + en) / 2;

		if (b[mid] > t) en = mid - 1;
		else if (b[mid] < t) st = mid + 1;
		else return true;
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int A, B;

	cin >> A >> B;

	for (int i = 0; i < A; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < B; i++) {
		cin >> b[i];
	}
	sort(b, b + B);
	vector<int> ans;

	for (int i = 0; i < A; i++) {
		if (!bs(B, a[i])) {
			ans.push_back(a[i]);
		}
	}
	sort(ans.begin(), ans.end());

	cout << ans.size() << "\n";

	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}