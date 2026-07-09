#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    
    
    int w_size = weak.size();
    int d_size = dist.size();
    for(int i=0; i<w_size; i++) {
        weak.push_back(n + weak[i]);
    }
    
    int answer = d_size+1;
    
    sort(dist.begin(), dist.end());
    for(int s = 0; s < w_size; s++){
        do {
            int cnt = 1;
            int pos = weak[s] + dist[cnt - 1];
            
            for (int i=s; i < s+w_size; i++) {
                if (pos < weak[i]) {
                    cnt++;
                    
                    if (cnt > d_size) break;
                    
                    pos = weak[i] + dist[cnt-1];
                }    
            }
            
            if (cnt <= d_size) {
                answer = min(answer, cnt);
            }
        } while(next_permutation(dist.begin(), dist.end()));    
    }
    
    
    
    return answer > d_size ? -1 : answer;
}