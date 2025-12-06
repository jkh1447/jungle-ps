#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    // 앞에서부터 3의 배수로 맞춤
    int r = s.size() % 3;
    if (r == 1) s = "00" + s;
    else if (r == 2) s = "0" + s;

    string ans;
    for (int i = 0; i < s.size(); i += 3) {
        int val = (s[i] - '0') * 4 +
                  (s[i+1] - '0') * 2 +
                  (s[i+2] - '0') * 1;
        ans += char('0' + val);
    }

    // 앞의 불필요한 leading zero 제거
    if (ans[0] == '0' && ans.size() > 1) {
        ans.erase(ans.begin());
    }

    cout << ans;
}
