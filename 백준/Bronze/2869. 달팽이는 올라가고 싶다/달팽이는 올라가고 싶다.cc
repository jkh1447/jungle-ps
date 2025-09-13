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
#include <cctype>
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };



int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A, B, V;
	cin >> A >> B >> V;

	if ((V - A) % (A - B) == 0) {
		cout << (V - A) / (A - B) + 1;
	}
	else {
		cout << (V - A) / (A - B) + 2;
	}

}
