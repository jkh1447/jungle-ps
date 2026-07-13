#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
unordered_map<long long, long long> p;

long long find(long long u) {
    auto it = p.find(u);
    if (it != p.end()) return it->second = find(it->second);
    else return u;
}

bool uni(long long u, long long v){
    u = find(u);
    v = find(v);
    if (u == v) return false;
    
    p[v] = u;
    return true;
}
vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    // 1번 방에 배정하면, 1번과 2번을 union해서 1번의 부모를 2번으로 uni(2, 1) 으로 해서 1번 다차면 find로 한 번에 찾아갈 수 있도록, 
    
    for(int i=0; i<room_number.size(); i++){
        long long num = room_number[i];
        if (p.find(num) == p.end()) {
            uni(num+1, num);
            answer.push_back(num);   
        }   
        else {
            long long next = find(num);
            uni(next+1, next);
            answer.push_back(next);
        }
    }
    
    return answer;
}