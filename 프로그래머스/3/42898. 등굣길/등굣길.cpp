#include <string>
#include <vector>
#include <bits/stdc++.h>



using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    long long C = 1'000'000'007;
    vector<vector<int>> v(n, vector<int>(m, 0));
    if(puddles.size() > 0){
        for(auto p: puddles) {
            v[p[1]-1][p[0]-1] = -1;
        }
    }

    
    int d = 1;
    for(int j=1; j<m; j++){
        if(v[0][j] == -1) d = 0;
        else v[0][j] = d;
    }
    d = 1;
    for(int i=1; i<n; i++){
        if(v[i][0] == -1) d = 0;
        else v[i][0] = d;
    }
    
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(v[i][j] == -1) continue;
            if(v[i][j-1] != -1) v[i][j] += (v[i][j-1] % C);
            if(v[i-1][j] != -1) v[i][j] += (v[i-1][j] % C);
            
        }
    }

    answer = v[n-1][m-1] % C;
    return answer;
}