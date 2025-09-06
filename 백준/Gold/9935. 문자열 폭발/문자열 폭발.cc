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




int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	string bomb;
	cin >> s;
	cin >> bomb;

	deque<char> dq;

	for (char nxt : s) {
		dq.push_back(nxt);

		if (dq.size() >= bomb.size() && bomb[bomb.size() - 1] == dq.back()) {
			bool flag = true;
			int bs = bomb.size();
			int bidx = bs - 1;
			int dqidx = dq.size() - 1;
			while (bs--) {
				if (dq[dqidx] != bomb[bidx]) {
					flag = false;
					break;
				}
				dqidx--;
				bidx--;
			}

			if (flag) {
				for (int i = 0; i < bomb.size(); i++) {
					dq.pop_back();
				}
			}
		}
	}
	if (dq.empty()) cout << "FRULA";
	else for (int i = 0; i < dq.size(); i++) cout << dq[i];
}
