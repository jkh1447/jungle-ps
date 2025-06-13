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

	long long tmp = 0;
	long long ans = 0;

	for (char c : s) {
		if ('0' <= c && c <= '9') {
			tmp *= 10;
			tmp += c - '0';
		}
		else {
			ans += tmp;
			tmp = 0;
		}
	}
	ans += tmp;
	cout << ans;
}