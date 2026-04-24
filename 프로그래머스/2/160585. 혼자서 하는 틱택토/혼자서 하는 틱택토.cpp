#include <string>
#include <vector>

using namespace std;

bool ans = false;

void solve(vector<string>& board, char turn, vector<string>& p) {
    
    bool ok = false;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++){
            if (board[i][j] != p[i][j]) {
                ok = true;
                break;
            }
        }
        if (ok) break;
    }
    if (!ok) {
        ans = true;
        return;
    }
    
    bool isEnd = false;
    for (int i = 0; i < 3; i++) {
        if (p[i][0] != '.' && p[i][0] == p[i][1] && p[i][1] == p[i][2]) {
            isEnd = true;
            break;
        }
    }
    for (int j = 0; j < 3; j++) {
        if (p[0][j] != '.' && p[0][j] == p[1][j] && p[1][j] == p[2][j]) {
            isEnd = true;
            break;
        }
    }

    if (p[0][0] != '.' && p[0][0] == p[1][1] && p[1][1] == p[2][2]) isEnd = true;
    if (p[0][2] != '.' && p[0][2] == p[1][1] && p[1][1] == p[2][0]) isEnd = true;

    if (isEnd) {

        return;
    }
    
    for(int i=0; i<3; i++){
        for (int j = 0; j<3; j++){
            if (p[i][j] != '.') continue;
            
            p[i][j] = turn;
            solve(board, turn == 'O' ? 'X' : 'O', p);
            p[i][j] = '.';
            
            
        }
    }
}

int solution(vector<string> board) {
    int answer = -1;
    vector<string> p = {"...", "...", "..."};
    solve(board, 'O', p);
    if (ans) return 1;
    else return 0;
    return 1;
}