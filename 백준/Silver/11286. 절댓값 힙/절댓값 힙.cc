#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };

int arr[1004];
vector<int> v1;
vector<int> v2;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> positiveMinHeap;
	priority_queue<int, vector<int>, greater<int>> negativeMinHeap;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;

		if (tmp > 0) {
			positiveMinHeap.push(tmp);
		}
		else if (tmp < 0) {
			negativeMinHeap.push(-tmp);
		}
		else {
			if (positiveMinHeap.empty() || negativeMinHeap.empty()) {
				if (positiveMinHeap.empty() && !negativeMinHeap.empty()) {
					cout << -negativeMinHeap.top() << "\n";
					negativeMinHeap.pop();
				}
				else if (negativeMinHeap.empty() && !positiveMinHeap.empty()) {
					cout << positiveMinHeap.top() << "\n";
					positiveMinHeap.pop();
				}
				else 
					cout << 0 << "\n";
			}
			else {
				if (positiveMinHeap.top() < negativeMinHeap.top()) {
					cout << positiveMinHeap.top() << "\n";
					positiveMinHeap.pop();
				}
				else {
					cout << -negativeMinHeap.top() << "\n";
					negativeMinHeap.pop();
				}
			}
		}
	}

	
	
	


}