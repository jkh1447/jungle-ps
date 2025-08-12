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
	
	int N, M;
	unordered_map<string, string> plist;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string site, pwd;

		cin >> site >> pwd;

		plist[site] = pwd;

	}

	for (int i = 0; i < M; i++) {
		string site;
		cin >> site;

		cout << plist[site] << "\n";
	}

}