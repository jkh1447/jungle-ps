#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

deque<int> dq;
int ans = 0;
void solve(vector<vector<int>>& board, int col) {
    int n = board.size();
    
    for(int i=0; i<n; i++){
        if (board[i][col] != 0) {
            
            if (dq.empty()) dq.push_back(board[i][col]);
            else if (!dq.empty() && dq.back() == board[i][col]) {
                dq.pop_back();
                ans += 2;    
            }
            else dq.push_back(board[i][col]);
            
            board[i][col] = 0;
            break;
        }
    }
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    for(int i=0; i<moves.size(); i++){
        solve(board, moves[i]-1);
    }
    answer = ans;
    
    return answer;
}