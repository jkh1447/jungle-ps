#include <bits/stdc++.h>
using namespace std;	


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	getline(cin, str);
	stack<char> s;
	int ans = 0;
	int stick = 0;
	for (char c : str) {
		if (c == '(') {
			s.push(c);
			stick++;
		}
		else {
			//cout << "s.top(): " << s.top() << "\n";
			if (s.top() == '(') {
				s.push(c);
				stick--;
				ans += stick;
				//cout << "ans+=stick"<< "\n";
			}
			else {
				s.push(c);
				stick--;
				ans++;
				//cout << "ans++" << "\n";
			}
		}
		//cout << "stick: " << stick << "\n";
		//cout << "ans: " << ans << "\n";
	}

	cout << ans;
}