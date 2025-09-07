#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <string>
#include <stack>
#include <deque>
using namespace std;

#define X first
#define Y second

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };

int N, M;
int path[10];

void func(int n) {
	if (n == M + 1) {
		for (int i = 1; i <= M; i++) cout << path[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {

		path[n] = i;
		func(n + 1);
		path[n] = 0;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	func(1);

}
