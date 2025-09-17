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

int arr[52];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	int st = 0;
	long long ans = 0;

	if (n < 2) ans += arr[0];
	else {

		while(true){
			if (arr[st] > 0 || arr[st + 1] > 0) break;
			ans += arr[st] * arr[st + 1];
			st += 2;
		}

		int en = n - 1;
		while (true) {
			if (en <= st) break;
			if (arr[en] <= 0 || arr[en - 1] <= 0) break;
			if (arr[en] == 1 || arr[en - 1] == 1) break;
			ans += arr[en] * arr[en - 1];
			en -= 2;
		}

		for (int i = st; i <= en; i++) ans += arr[i];

	}
	cout << ans;

}
