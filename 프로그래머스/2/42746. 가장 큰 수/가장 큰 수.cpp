#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> s;
    for(int i=0; i<numbers.size(); i++){
        s.push_back(to_string(numbers[i]));
    }
    
    sort(s.begin(), s.end(), [](string a, string b) {
        return a+b > b+a ;
    });
    
    if(s[0] == "0") return "0";
    
    for(auto nxt: s){
        answer += nxt;
    }
    
    return answer;
}