#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int xpy = (brown + 4) / 2;
    int xy = brown + yellow;
    int w, h;
    for(int i=1; i<=xy; i++){
        if(xy % i != 0) continue;
        int x = i;
        int y = xy / x;
        if(x+y == xpy) {
            w = x;
            h = y;
            break;
        }
    }
    if (w < h) swap(w, h);
    answer.push_back(w);
    answer.push_back(h);
    return answer;
}