#include <bits/stdc++.h>
using namespace std;	


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		bool no = false;
		string s;
		getline(cin, s);
		if (s == ".") break;
		stack<char> st;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '[') {
				st.push(s[i]);
			}
			else if (s[i] == ')') {
				if (st.empty()) {
					no = true;
					break;
				}
				if (st.top() == '(') st.pop();
				else {
					no = true;
					break;
				}
			}
			else if (s[i] == ']') {
				if (st.empty()) {
					no = true;
					break;
				}
				if (st.top() == '[') st.pop();
				else {
					no = true;
					break;
				}
			}
		}

		if (st.size() > 0) no = true;

		if (no) cout << "no\n";
		else cout << "yes\n";
	
	}
}