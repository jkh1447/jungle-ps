#include <bits/stdc++.h>
using namespace std;

int A[2000000];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int an, bn;
	cin >> an >> bn;

	for (int i = 0; i < an+bn; i++) cin >> A[i];
	sort(A, A + an + bn);
	for (int i = 0; i < an + bn; i++) {
		cout << A[i] << " ";
	}

}