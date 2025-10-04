#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
int maxval = 0;
vector<int> maxa;

void func(int n, int a, int st, vector<int>& path, vector<int>& info){
    if (a == n) {
        int ascore = 0, lscore = 0;
        for(int i=0; i<info.size(); i++){
            int apeach = info[i], lion = path[i];
            if (apeach == 0 && lion == 0) continue;
            if (apeach == lion) {
                ascore += 10 - i;
            }
            else if (apeach < lion) lscore += 10 - i;
            else if (apeach > lion) ascore += 10 - i;
        }
        if(lscore - ascore == maxval && maxa.empty()) return;
        if(lscore - ascore > maxval) {
            maxval = lscore - ascore;
            maxa = path;
        }
        else if (lscore - ascore == maxval){
            for(int i=10; i>=0; i--){
                if(path[i] > maxa[i]) {
                    maxa = path;
                    break;
                }
                else if (path[i] < maxa[i]) break;
            }
        }
        return;
    }
    
    for(int i=st; i<path.size(); i++){
        path[i]++;
        func(n, a+1, i, path, info);
        path[i]--;
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> path(11, 0);
    func(n, 0, 0, path, info);
    
    if (maxval == 0 && maxa.empty()) return {-1};
    else return maxa;
}