#include <string>
#include <vector>
#include <bits/stdc++.h>


using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for(int i=0; i<progresses.size(); i++){
        int remain = 100 - progresses[i];
        if(remain % speeds[i] == 0){
            q.push(remain/speeds[i]);
        }
        else q.push(remain/speeds[i] + 1);
        
    }

    int max = q.front();
    q.pop();
    int cnt = 1;
    while(!q.empty()){
        if(max < q.front()){
            answer.push_back(cnt);
            max = q.front();
            q.pop();
            cnt = 1;
        }
        else {
            cnt++;
            q.pop();
        }
        
    }
    
    answer.push_back(cnt);
    
    
    
    return answer;
}