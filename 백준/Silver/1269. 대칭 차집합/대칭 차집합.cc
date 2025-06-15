#include <bits/stdc++.h>
using namespace std;


int A[200001];
int B[200001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	unordered_map<int, bool> mapA;
	unordered_map<int, bool> mapB;
	cin >> a >> b;

	for (int i = 0; i < a; i++) {
		int tmp;
		cin >> tmp;
		mapA[tmp] = true;
		A[i] = tmp;
	}
	for (int i = 0; i < b; i++) {
		int tmp;
		cin >> tmp;
		mapB[tmp] = true;
		B[i] = tmp;
	}
	int ans = 0;
	for (int i = 0; i < a; i++) {
		if (mapB.find(A[i]) == mapB.end()) ans++;
	}

	for (int i = 0; i < b; i++) {
		if (mapA.find(B[i]) == mapA.end()) ans++;
	}
	cout << ans;
}