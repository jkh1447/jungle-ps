#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool findPair(set<int>& s1, set<int>& s2, int target) {
    for (int card: s1) {
        int cha = target - card;
        if(s2.count(cha)) {
            s1.erase(card);
            s2.erase(cha);
            return true;
        }
    }
    return false;
}

int solution(int coin, vector<int> cards) {
    int answer = 0;
    
    int n = cards.size();
    int target = n + 1;
    int idx = n/3;
    int round = 1;
    
    set<int> myHand;
    set<int> candidate;
    
    for(int i=0; i<idx; i++){
        myHand.insert(cards[i]);
    }
    
    while(idx < n) {
        candidate.insert(cards[idx++]);
        candidate.insert(cards[idx++]);
        
        bool possible = false;
        
        if (findPair(myHand, myHand, target)) possible = true;
        else if (coin >= 1 && findPair(myHand, candidate, target)) {
            coin -= 1;
            possible = true;
        }
        else if (coin >= 2 && findPair(candidate, candidate, target)) {
            coin -= 2;
            possible = true;
        }
        
        if (!possible) break;
        
        round++;
    }
    answer = round;
    return answer;
}