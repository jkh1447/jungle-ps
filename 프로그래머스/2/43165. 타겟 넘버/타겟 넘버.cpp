#include <string>
#include <vector>

using namespace std;
int ans = 0;
void dfs(int target, int c, int st ,vector<int> &numbers, vector<int> &path) {
    if(c != 0){
        int hap = 0;
        for(int i = 0; i<path.size(); i++){
            hap += path[i] == 1 ? numbers[i] : -numbers[i];
        }
        if (hap == target) ans++;
    }
    for(int i=st; i<path.size(); i++){
        path[i] = 1;
        dfs(target, c+1, i + 1, numbers, path);
        path[i] = 0;
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    vector<int> path(numbers.size(), 0);
    dfs(target, 0, 0, numbers, path);
    answer = ans;
    return answer;
}