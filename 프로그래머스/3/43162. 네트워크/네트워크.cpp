#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> p;

// 1 1 0
// 1 1 0
// 0 0 1

int find(int x) {
    if (p[x] < 0)
        return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    p[v] = u;
    return true;
}

int solution(int n, vector<vector<int>> computers) {
    int ans = n;
    p.resize(n, -1);
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if (computers[i][j] == 1) {
                if(uni(i, j)) ans--;
            }
        }
    }
    
    return ans;
}