#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int d = n-1;
    int p = n-1;
    
    while(d >=0 || p >= 0) {
        
        while(d >= 0 &&deliveries[d] == 0) d--;
        while(p >= 0 &&pickups[p] == 0) p--;
        
        answer += (2LL * max(d+1, p+1));
        
        
        int delcap = cap;
        while(d >=0 && delcap > 0) {
            if(deliveries[d] == 0) {d--; continue;}
            int take = min(delcap, deliveries[d]);
            deliveries[d] -= take;
            delcap -= take;
            if(deliveries[d] == 0) d--;
        }
        
        int pickcap = cap;
        while(p >=0 && pickcap > 0) {
            if(pickups[p] == 0) {p--; continue;}
            int take = min(pickcap, pickups[p]);
            pickups[p] -= take;
            pickcap -= take;
            if(pickups[p] == 0) p--;
        }
        
    }
    
    
    return answer;
}