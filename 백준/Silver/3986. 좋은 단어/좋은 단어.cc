#include <bits/stdc++.h>
using namespace std;	


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	int ans = 0;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		stack<char> s;

		for (int j = 0; j < str.size(); j++) {
			if (s.empty() || s.top() != str[j]) s.push(str[j]);
			else s.pop();
		}

		if (s.empty()) ans++;
	}

	cout << ans;
}