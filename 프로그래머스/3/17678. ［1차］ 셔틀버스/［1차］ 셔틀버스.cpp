#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<string> split(string s, string delimiter) {
    vector<string> token;
    int pos = 0;
    while(pos < s.size()) {
        int nxt_pos = s.find(delimiter, pos);
        if (nxt_pos == -1) nxt_pos = s.size();
        if (nxt_pos - pos > 0) token.push_back(s.substr(pos, nxt_pos - pos));
        pos = nxt_pos + delimiter.size();
    }
    return token;
}

string solution(int n, int t, int m, vector<string> timetable) {
    int answer = 0;
    int START = 9 * 60;

    sort(timetable.begin(), timetable.end());
    vector<int> new_timetable;
    for(int i=0; i<timetable.size(); i++){
        vector<string> times = split(timetable[i], ":");
        int time = stoi(times[0]) * 60 + stoi(times[1]);
        new_timetable.push_back(time);
    }
    int cur = START;
    int idx = 0;
    for(int i=0; i<n; i++) {
        
        int cnt = 0;
        while(idx < new_timetable.size() && new_timetable[idx] <= cur && cnt < m) {
            cnt++;
            idx++;
        }
        if (cnt < m) {
            answer = max(answer, cur);
        }
        else {
            answer = max(answer, new_timetable[idx-1]-1);
        }
        
        cur = cur + t;
    }

    int hour = answer / 60;
    int minute = answer % 60;
    string ans = "";
    if (hour < 10) ans += "0" + to_string(hour);
    else ans += to_string(hour);
    ans += ":";
    if (minute < 10) ans += "0" + to_string(minute);
    else ans += to_string(minute);

    return ans;
}