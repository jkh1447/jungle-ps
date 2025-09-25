#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, 0));
    
    int num = 2;
    answer[0][0] = 1;
    int curX = 0, curY = 0;
    int dir = 0;
    while(num <= n * n) {
        int nx = curX + dx[dir];
        int ny = curY + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) {
            dir = (dir + 1) % 4;
            continue;
        }
        if(answer[nx][ny] != 0) {
            dir = (dir + 1) % 4;
            continue;   
        }
        answer[nx][ny] = num;
        num++;
        curX = nx; curY = ny;
    }
    
    
    
    return answer;
}