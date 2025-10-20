#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    cin >> m;
    vector<int> B(m);
    for (int i = 0; i < m; i++) cin >> B[i];

    int aidx = 0, bidx = 0;
    vector<int> ans;

    while (aidx < n && bidx < m) {
        int maxval = -1;
        int na = -1, nb = -1;
        bool flag = false;

        for (int i = aidx; i < n; i++) {
            for (int j = bidx; j < m; j++) {
                if (A[i] == B[j]) {
                    if (A[i] > maxval) {
                        maxval = A[i];
                        na = i;
                        nb = j;
                        flag = true;
                    }
                }
            }
        }

        if (!flag) break;

        ans.push_back(maxval);
        aidx = na + 1;
        bidx = nb + 1;
    }

    cout << ans.size() << "\n";
    for (int x : ans) cout << x << " ";
}