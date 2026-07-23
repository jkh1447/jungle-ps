#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int n;
int m;
int e_m;

void rotate (vector<vector<int>>& key) {
    vector<vector<int>> tmp(n, vector<int>(n, 0));
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            tmp[j][n-1-i] = key[i][j];
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            key[i][j] = tmp[i][j];
        }
    }
}

bool check(vector<vector<int>>& key, vector<vector<int>>& lock, int sx, int sy) {
    vector<vector<int>> nl(e_m, vector<int>(e_m, 0));
    for(int i=0; i<e_m; i++) {
        for(int j=0; j<e_m; j++) {
            nl[i][j] = lock[i][j];
        }
    }
                           
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if (key[i][j] == 1) {
                nl[sx+i][sy+j] = 1 - nl[sx+i][sy+j];
            }
        }
    }
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<m; j++) {
            if (nl[n-1+i][n-1+j] != 1) {
                return false;
            }
        }
    }
    
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    
    n = key.size();
    m = lock.size();
    
    e_m = m + ((n-1) * 2);
    
    vector<vector<int>> e_lock(e_m, vector<int>(e_m, 0));
    for(int i=0; i<m; i++) {
        for(int j=0; j<m; j++) {
            e_lock[i + (n-1)][j + (n-1)] = lock[i][j];
        }
    }
    
    for(int k=0; k<4; k++) {

        for(int i=0; i<e_m-n+1; i++) {
            for(int j=0; j<e_m-n+1; j++) {
                if (check(key, e_lock, i, j)) {
                    return true;
                }
            }
        }
        rotate(key);
    }
    
    
    
    
    return answer;
}