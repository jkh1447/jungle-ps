#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };

vector<int> adj[200];
int dist[200];
int score[200];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int K, L;

	cin >> K >> L;

	list<string> waiting;
	unordered_map<string, list<string>::iterator> um;
	
	for (int i = 0; i < L; i++) {

		string student;

		cin >> student;

		if (um.find(student) == um.end()) {
			waiting.push_back(student);	
			um[student] = --waiting.end();
		}
		else {
			waiting.erase(um[student]);
			waiting.push_back(student);
			um[student] = --waiting.end();
		}

	}

	list<string>::iterator cur = waiting.begin();
	for (int i = 0; i < K && i < waiting.size() ; i++) {
		cout << *cur << "\n";
		cur++;
	}

}