#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string answer = "";
    int mode = 0;
    for(int i=0; i<code.size(); i++){
        if(mode){
            if(code[i] != '1') {
                if(i % 2 == 0) continue;
                answer += code[i];
            }
            else {
                mode = 0;
            }
        }
        else{
            if(code[i] != '1'){
                if(i % 2 != 0) continue;
                answer += code[i];
            }
            else mode = 1;
        }
        
    }
    
    if(answer.size() == 0) return "EMPTY";
    
    return answer;
}