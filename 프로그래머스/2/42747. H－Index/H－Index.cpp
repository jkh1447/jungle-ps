#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    int h=0;
    sort(citations.begin(), citations.end(), greater<>());
    for(int i=0; i<citations.size(); i++) {
        if (citations[i] > h) h++;
    }
    return h;
}