#include <bits/stdc++.h>
using namespace std;

int A[1000000];
int B[1000000];
int C[2000000];


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int an, bn;
	cin >> an >> bn;

	for (int i = 0; i < an; i++) cin >> A[i];
	for (int i = 0; i < bn; i++) cin >> B[i];

	int cur = 0;
	int cura = 0, curb = 0;
	while (cur != an + bn) {
		if (cura == an) {
			C[cur] = B[curb];
			curb++;
			cur++;
			continue;
		}
		else if(curb == bn) {
			C[cur] = A[cura];
			cura++;
			cur++;
			continue;
		}

		if (A[cura] >= B[curb]) {
			C[cur] = B[curb];
			curb++;
		}
		else {
			C[cur] = A[cura];
			cura++;
		}
		cur++;
	}
	for (int i = 0; i < an + bn; i++) cout << C[i] << " ";
}