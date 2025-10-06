#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int ans = 0;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    for(int i=0; i<(1 << numbers.size()); i++){
        int cur = i;
        int hap = 0;
        for(int j=0; j<numbers.size(); j++){
            int digit = cur % 2;
            cur = cur / 2;
            hap += digit == 1 ? -numbers[j] : numbers[j];
        }
        if(hap == target) answer++;
    }
    
    return answer;
}