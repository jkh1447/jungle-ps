#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<string> split(string s, string deli) {
    vector<string> tokens;
    int pos = 0;
    while(pos < s.size()) {
        int nxt_pos = s.find(deli, pos);
        if (nxt_pos == -1) nxt_pos = s.size();
        if (nxt_pos - pos > 0)
            tokens.push_back(s.substr(pos, nxt_pos - pos));
        pos = nxt_pos + deli.size();
    }
    return tokens;
}

string replaceSharp(string s) {
    string res = "";
    for(int i=0; i<s.size(); i++){
        if (i < s.size()-1 && s[i+1] == '#') {
            res += tolower(s[i]);
            i++;
        }
        else res += s[i];
    }
    return res;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    
    int maxR = 0;
    
    for(int i=0; i<musicinfos.size(); i++){
        vector<string> tmp = split(musicinfos[i], ",");
        vector<string> startStr = split(tmp[0], ":");
        vector<string> endStr = split(tmp[1], ":");
        
        int start = stoi(startStr[0]) * 60 + stoi(startStr[1]);
        int end = stoi(endStr[0]) * 60 + stoi(endStr[1]);
        int runningTime = end - start;
        string name = tmp[2];
        string music = tmp[3];
        string entireMusic = "";
        
        music = replaceSharp(music);
        
        for(int j=0; j<runningTime; j++){
            entireMusic += music[j % music.size()];
        }
        
        if (entireMusic.find(replaceSharp(m)) != -1) {
            if (runningTime > maxR) {
                maxR = runningTime;
                answer = name;
            }
        }
        
    }
    
    if (answer == "") answer = "(None)";
    
    return answer;
}