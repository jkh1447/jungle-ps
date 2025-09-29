#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int maxW = 0, maxH = 0;
    for(auto s: sizes){
        int width = max(s[0], s[1]);
        int height = min(s[0], s[1]);
        maxW = max(maxW, width);
        maxH = max(maxH, height);
    }
    answer = maxW * maxH;
    
    return answer;
}