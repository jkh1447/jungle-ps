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

	long ans = 0;
	long tmp = 0;
	long mul = 1;
	for (int i = n-1; i >= 0; i--) {
		if (!isdigit(s[i])) {
			
			ans += tmp;
			tmp = 0;
			mul = 1;
			continue;
		}
		tmp += (s[i] - '0') * mul;
		mul *= 10;
	}
	ans += tmp;
	cout << ans;
	
}