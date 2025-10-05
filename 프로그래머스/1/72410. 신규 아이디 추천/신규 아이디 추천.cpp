#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

string solution(string new_id) {
    string answer = "";
    
    // 1
    for(int i=0; i<new_id.size(); i++){
        if('A' <= new_id[i] && new_id[i] <= 'Z') new_id[i] = new_id[i] + ('a' - 'A');
    }
    cout << new_id<< "\n";
    // 2
    for(int i=new_id.size()-1; i>=0; i--){
        if('a' <= new_id[i] && new_id[i] <= 'z') continue;
        if('0' <= new_id[i] && new_id[i] <= '9') continue;
        if(new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') continue;
        new_id.erase(i, 1);
    }
    cout << new_id << "\n";
    // 3
    int st = -1, en = -1;
    for(int i=new_id.size()-2; i>=0; i--){
        if(new_id[i] == '.' && new_id[i] == new_id[i+1]) new_id.erase(i+1, 1);
    }
    cout << new_id<< "\n";
    // 4
    if(new_id[0] == '.') new_id.erase(0, 1);
    if(new_id[new_id.size()-1] == '.') new_id.erase(new_id.size()-1, 1);
    cout << new_id<< "\n";
    // 5
    if(new_id.empty()) new_id += "a";
    cout << new_id<< "\n";
    // 6
    if(new_id.size() >= 16) new_id = new_id.substr(0, 15);
    if(new_id[new_id.size()-1] == '.') new_id.erase(new_id.size()-1, 1);
    cout << new_id<< "\n";
    // 7
    if(new_id.size() <= 2) {
        while(new_id.size() < 3) new_id += new_id.back();
    }
    cout << new_id<< "\n";
    answer = new_id;
    return answer;
}