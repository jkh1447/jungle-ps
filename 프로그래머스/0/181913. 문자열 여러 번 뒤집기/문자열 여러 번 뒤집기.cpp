#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    string answer = "";
    
    for(int i=0; i<queries.size(); i++){
        int s, e;
        s = queries[i][0]; e = queries[i][1];
        reverse(my_string.begin()+s, my_string.begin() + e+1);
    }
    answer = my_string;
    return answer;
}