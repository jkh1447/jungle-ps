#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };

int arr[305];
int one[305];
int two[305];

// 0    10    20    15    25    10    20
// 0    10    30    35    50    65    65
// 0     0      20    25    55    45    75

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// 초기 설정
	one[0] = arr[0];
	
	one[1] = arr[0] + arr[1];
	two[1] = arr[1];

	for (int i = 2; i < n; i++) {
		one[i] = two[i - 1] + arr[i];
		two[i] = max(one[i - 2], two[i - 2]) + arr[i];
	}

	//cout << "one: \n";
	//for (int i = 0; i < n; i++) {
	//	cout << one[i] << " ";
	//}
	//cout << "\n";
	//cout << "two: \n";
	//for (int i = 0; i < n; i++) {
	//	cout << two[i] << " ";
	//}
	//cout << "\n";
	cout << max(one[n - 1], two[n - 1]);


}