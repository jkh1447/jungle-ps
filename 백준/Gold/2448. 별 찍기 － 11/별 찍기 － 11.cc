#include <bits/stdc++.h>
using namespace std;


char board[3100][6200];

void func(int x, int y, int h) {
    if (h == 3) {
        board[x][y] = '*';
        board[x+1][y-1] = '*';
        board[x + 1][y + 1] = '*';
        board[x + 2][y - 2] = '*';
        board[x + 2][y - 1] = '*';
        board[x + 2][y] = '*';
        board[x + 2][y + 1] = '*';
        board[x + 2][y + 2] = '*';
        return;
    }
    func(x, y, h / 2);
    func(x + h / 2, y - h / 2, h / 2);
    func(x + h / 2, y + h / 2, h / 2);
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        fill(board[i], board[i] + (2 * n - 1), ' ');
    }

    func(0, n-1, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (2 * n - 1); j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}