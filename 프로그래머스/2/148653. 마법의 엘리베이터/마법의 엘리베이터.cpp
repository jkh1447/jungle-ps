#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int dist[100'000'001];

int solution(int storey) {


    int answer = 0;

    while (storey > 0) {
        int current_digit = storey % 10;
        int next_digit = (storey / 10) % 10;

        if (current_digit < 5) {
            answer += current_digit;
        }
        else if (current_digit > 5) {
            answer += (10 - current_digit);
            storey += (10 - current_digit);
        }
        else if (current_digit == 5) {
            if (next_digit >= 5) {
                answer += (10 - current_digit);
                storey += (10 - current_digit);
            } else {
                answer += current_digit;
            }
        }
        
        storey /= 10;
    }


    
    
    return answer;
}