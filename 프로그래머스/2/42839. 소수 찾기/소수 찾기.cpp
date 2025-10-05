#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for(int i=3; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

map<int, bool> vis;
int solution(string numbers) {
    int answer = 0;
    
    for(int i=1; i<=numbers.size(); i++){
        vector<int> bitmask(numbers.size() - i, 0);
        bitmask.insert(bitmask.end(), i, 1);
        do{
            string s;
            
            for(int i=0; i<bitmask.size(); i++){
                if(bitmask[i]) s += numbers[i];
            }
            sort(s.begin(), s.end());
            do{
                if(vis[stoi(s)]) continue;
                if(isPrime(stoi(s))) {
                    answer++;
                    
                }
                vis[stoi(s)] = true;

            } while(next_permutation(s.begin(), s.end()));
        } while(next_permutation(bitmask.begin(), bitmask.end()));
    }

    
    return answer;
}