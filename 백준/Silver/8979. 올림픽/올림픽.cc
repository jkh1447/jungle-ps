#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<tuple<int,int,int,int>> v;

    for (int i = 0; i < n; i++) {
        int nation, g, s, c;
        cin >> nation >> g >> s >> c;
        v.emplace_back(nation, g, s, c);
    }

    sort(v.begin(), v.end(), [](const auto& a, const auto& b){
        if (get<1>(a) != get<1>(b)) return get<1>(a) > get<1>(b);
        if (get<2>(a) != get<2>(b)) return get<2>(a) > get<2>(b);
        return get<3>(a) > get<3>(b);
    });

    vector<int> rank(n);
    rank[0] = 1;

    for (int i = 1; i < n; i++) {
        if (get<1>(v[i]) == get<1>(v[i - 1]) &&
            get<2>(v[i]) == get<2>(v[i - 1]) &&
            get<3>(v[i]) == get<3>(v[i - 1])) {
            rank[i] = rank[i - 1];
        } else {
            rank[i] = i + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (get<0>(v[i]) == k) {
            cout << rank[i];
            return 0;
        }
    }
}
