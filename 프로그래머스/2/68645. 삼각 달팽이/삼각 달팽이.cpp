#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int dx[] = {1, 0, -1};
int dy[] = {0, 1, -1};

vector<int> solution(int n) {
    vector<int> answer;
    
    vector<vector<int>> board(n, vector<int>(n, 0));
    int i=1;
    int x = 0, y = 0;
    int dir = 0;
    while(true) {
        if (board[x][y] != 0) break;
        board[x][y] = i; i++;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= n || ny >= n || board[nx][ny] != 0) {
            dir = (dir + 1) % 3;
        }
        x = x + dx[dir];
        y = y + dy[dir];
        
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            if (board[i][j] != 0)
                answer.push_back(board[i][j]);
        }

    }
    return answer;
}