#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int N = triangle[triangle.size()-1].size();
    vector<vector<int>> v(N, vector<int> (N));
    v[0][0] = triangle[0][0];
    for(int i=0; i<triangle.size()-1; i++){
        for(int j=0; j<triangle[i].size(); j++){
            v[i+1][j] = max(v[i+1][j], v[i][j] + triangle[i+1][j]);
            v[i+1][j+1] = max(v[i+1][j+1], v[i][j] + triangle[i+1][j+1]);
        }
    }

    
    answer = *max_element(v[N-1].begin(), v[N-1].end());
    return answer;
}