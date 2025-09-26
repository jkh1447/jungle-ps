#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    
    vector<int> prev(arr.begin(), arr.end());
    while(true){
        for(int i=0; i<arr.size(); i++){
            if(arr[i] > 50 && arr[i] % 2 == 0) arr[i] = arr[i] / 2;
            else if (arr[i] < 50 && arr[i] % 2 != 0) arr[i] = arr[i] * 2 + 1;
        }
        answer++;
        
        bool flag = false;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] != prev[i]) {
                flag = true;
                break;
            }
        }
        prev = arr;

        if(!flag) break;
    }
    answer--;
    
    return answer;
}