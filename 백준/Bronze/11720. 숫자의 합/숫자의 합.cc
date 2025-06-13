#include <bits/stdc++.h>

using namespace std;

int arr[100];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	string s;
	cin >> s;
	int ans = 0;
	for (char c : s) {
		ans += c - '0';
	}

	cout << ans;
}