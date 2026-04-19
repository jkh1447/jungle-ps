#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    
    deque<int> dq;
    for(int i=0; i<ingredient.size(); i++){
        int cur = ingredient[i];
        
        if (cur == 1) {
            if (dq.size() < 3) {
                dq.push_back(cur);
                continue;
            }
            int s = dq.size();
            if (dq[s-1] == 3 && dq[s-2] == 2 && dq[s-3] == 1) {
                dq.pop_back(); dq.pop_back(); dq.pop_back();
                answer++;
            }
            else dq.push_back(cur);
        }
        else dq.push_back(cur);
    }
    
    return answer;
}