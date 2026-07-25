#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> land)
{

    int N = land.size();
    for (int i=1; i<N; i++) {
        for(int j=0; j<4; j++){
            int cur = land[i][j];
            for(int k=0; k<4; k++) {
                if (k == j) continue;
                land[i][j] = max(land[i][j], land[i-1][k] + cur);
            }
        }
    }
    
    return *max_element(land[N-1].begin(), land[N-1].end());

}