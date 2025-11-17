#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stack>
#include <deque>
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define LL long long

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };
int l[100'001];
int r[100'001];
int inorder[100'001];
stack<int> postorder;
int n;

int solve(int s, int e) {
    int root = postorder.top();
    postorder.pop();
    if (s == e) return inorder[s];
    int mid = find(inorder+s, inorder + e + 1, root) - inorder;
    if (mid < e) r[root] = solve(mid + 1, e);
    if (mid > s) l[root] = solve(s, mid - 1);
    return root;
}

void preorder(int cur) {
    cout << cur << " ";
    if (l[cur] != 0) preorder(l[cur]);
    if (r[cur] != 0) preorder(r[cur]);
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n;
    for (int i = 0; i < n; i++) cin >> inorder[i];
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        postorder.push(tmp);
    }
    int root = solve(0, n - 1);
    preorder(root);
}