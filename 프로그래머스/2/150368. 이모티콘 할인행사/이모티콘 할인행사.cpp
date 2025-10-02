#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {

    int dis[4] = {10, 20, 30, 40};
    pair<int, int> answer = {0, 0};
    for(int i=0; i<(1 << 2 * emoticons.size()); i++){
        pair<int, int> tmp = {0, 0};
        int cur = i;
        vector<int> discount;
        for(int j=0; j<emoticons.size(); j++){
            int digit = cur % 4;
            cur = cur / 4;
            discount.push_back(dis[digit]);
        }
        
        for(int j=0; j<users.size(); j++){
            int priceSum = 0;
            for(int k=0; k<discount.size(); k++){
                if(users[j][0] <= discount[k]){
                    priceSum += emoticons[k] * (100 - discount[k]) / 100;
                }
            }
            
            if(priceSum >= users[j][1]) {
                tmp.first++;
            }
            else tmp.second += priceSum;
        }
        
        if(answer.first == tmp.first) {
            if (answer.second < tmp.second) answer = tmp;
        }
        else if (answer.first < tmp.first) answer = tmp;
        
    }
    return {answer.first, answer.second};
}