#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    priority_queue<int, vector<int>> pq;
    
    for(int i=0; i<enemy.size(); i++){
        int cost = enemy[i];
        n -= cost;
        pq.push(cost);
        if (n < 0) {
            if (k > 0){
                int top = pq.top();
                pq.pop();
                n += top;
                k--;    
            }
            else break;
            
        }
        answer++;
    }
    
    return answer;
}