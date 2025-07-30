#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };

int arr[1000002];
vector<int> v1;
vector<int> v2;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		v1.push_back(arr[i]);

	}
	sort(v1.begin(), v1.end());
	
	for (int i = 0; i < n; i++) {
		if (i == 0 || v1[i - 1] != v1[i]) {
			v2.push_back(v1[i]);
		}
	}

	for (int i = 0; i < n; i++) {
		int target = arr[i];

		int st = 0;
		int en = v2.size();

		while (st < en) {
			int mid = (st + en) / 2;
		
			if (v2[mid] >= target) {
				en = mid;
			}
			else st = mid + 1;
		}
		cout << st << " ";
	}



}