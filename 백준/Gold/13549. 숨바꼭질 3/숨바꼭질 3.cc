#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int board[200002];


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    fill(board, board + 200002, -1);
    queue<int> q;
    q.push(n);
    board[n] = 0;

    while (board[k] == -1) {
        int cur = q.front();
        //cout << cur << "-> ";
        q.pop();

        if (0 <= cur * 2 && cur * 2 <= 200000) {
            if (board[cur * 2] == -1) {

                board[cur * 2] = board[cur];
                q.push(cur * 2);
            }
        }

        for (int next : { cur - 1, cur + 1}) {
            if (0 <= next && next <= 200000) {
                if (board[next] != -1) continue;
                board[next] = board[cur] + 1;
                q.push(next);
            }
        }
    }

    cout << board[k];
}