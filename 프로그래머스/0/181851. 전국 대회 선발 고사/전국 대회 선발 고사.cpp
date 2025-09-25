#include <string>
#include <vector>
#include <bits/stdc++.h>


using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    int answer = 0;
    vector<int> ok;
    vector<pair<int, int>> ra;
    for(int i=0; i<rank.size(); i++){
        if(attendance[i])
            ra.push_back({rank[i], i});
    }
    sort(ra.begin(), ra.end());
    answer = 10000 * ra[0].second + 100 * ra[1].second + ra[2].second;
    return answer;
}