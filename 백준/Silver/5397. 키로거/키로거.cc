#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용




int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int test = 0; test < t; test++) {
        string s;
        cin >> s;

        deque<char> dq;
        deque<char>::iterator cur = dq.begin();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '<') {
                if (cur == dq.begin()) continue;
                cur--;
            }
            else if (s[i] == '>') {
                if (cur == dq.end()) continue;
                cur++;
            }
            else if (s[i] == '-') {
                if (cur != dq.begin()) {

                    cur = dq.erase(prev(cur));
                }
            }
            else {
                cur = dq.insert(cur, s[i]) + 1;
                
            }
        }

        for (auto it = dq.begin(); it != dq.end(); it++) {
            cout << *it;
        }
        cout << "\n";
    }
}