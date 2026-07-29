#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> p(101, -1);

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u);
    v = find(v);
    if (u==v) return false;
    p[v] = u;
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int e = costs.size();
    sort(costs.begin(), costs.end(), [](auto& a, auto& b) {
        return a[2] < b[2];
    });
    int cnt = 0;
    for(int i=0; i<e; i++) {
        int u = costs[i][0], v = costs[i][1], cost = costs[i][2];

        if (!uni(u, v)) continue;
        answer += cost;
        cnt++;
        if (cnt == n-1) break;
    }
    return answer;
}