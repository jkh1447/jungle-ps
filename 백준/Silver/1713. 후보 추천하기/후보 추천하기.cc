#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stack>
#include <deque>
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define LL long long

//int dx[4] = { 1, 0, -1, 0 };
//int dy[4] = { 0, 1, 0, -1 };

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };


//int dx[6] = { 0, 1, 0, -1, 0, 0 };
//int dy[6] = { 1, 0, -1, 0, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };
//
//int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
//int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int nominate[101];
vector<pair<int, int>> photo(101);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    int nomi;
    cin >> nomi;
    int idx = 0;
    for (int i = 0; i < nomi; i++) {
        //for (int i = 0; i < n; i++) cout << photo[i].X << " ";
        //cout << "\n";
        int student;
        cin >> student;
        bool ok = false;
        for (int j = 0; j < n; j++) {
            if (photo[j].X == student) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            if (idx != n) {
                photo[idx++] = { student, i };
            }
            else {
                int min_idx = 0;
                int min_nomi = 10000;
                int old = -1;
                for (int j = 0; j < n; j++) {
                    if (nominate[photo[j].X] < min_nomi) {
                        min_nomi = nominate[photo[j].X];
                        min_idx = j;
                        old = photo[j].Y;
                    }
                    else if (nominate[photo[j].X] == min_nomi && old > photo[j].Y) {
                        min_nomi = nominate[photo[j].X];
                        min_idx = j;
                        old = photo[j].Y;
                    }
                }
                nominate[photo[min_idx].X] = 0;
                photo[min_idx] = { student, i };
            }
        
        }
        nominate[student]++;
    }
    set<int> ans;
    for (int i = 0; i < n; i++) {
        if(photo[i].X != 0)
            ans.insert(photo[i].X);

    }

    for (int nxt : ans) cout << nxt << " ";
}