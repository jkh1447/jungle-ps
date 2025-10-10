#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int maxd = 0;
void permutation(vector<vector<int>> &d, int hp, vector<int>& vis, vector<int> &path) {
    
    if (path.size() == d.size()) {
        int cnt = 0;
        for (int i = 0; i < path.size(); i++) {
            if (hp >= d[path[i]][0]) {
                hp -= d[path[i]][1];
                cnt++;
            }
            else break;
        }
        maxd = max(maxd, cnt);
        return;
    }


    for(int i=0; i<d.size(); i++){
        if(vis[i]) continue;
        vis[i] = 1;
        path.push_back(i);
        permutation(d, hp, vis, path);
        path.pop_back();
        vis[i] = 0;
    }
}
int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<int> vis(dungeons.size(), 0);
    vector<int> path;
    permutation(dungeons, k, vis, path);
    answer = maxd;
    
    return answer;
}