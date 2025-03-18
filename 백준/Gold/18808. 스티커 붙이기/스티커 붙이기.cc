#include <bits/stdc++.h>
using namespace std;



int n, m, k;
int board[41][41];
int sticker[11][11]; 
int r, c;

bool isavail(int x, int y) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (sticker[i][j] && board[x+i][y+j]) {
                //스티커 한 칸이 들어갈 수 없으면
                return false;
            }
        }
    }
    return true;
}

void stick(int x, int y) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (sticker[i][j]) {
                board[x + i][y + j] = 1;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int t = 0; t < k; t++) {

        cin >> r >> c;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> sticker[i][j];
            }
        }

        int count = 0;
        while (count < 5) {
            bool flag = false;
            for (int i = 0; i <= n - r; i++) {
                for (int j = 0; j <= m - c; j++) {
                    if (isavail(i, j)) {
                        stick(i, j);
                        flag = true;
                        break;
                    }
                }
                if (flag) break;
            }
            if (flag) break;

            if (!flag) { //회전
                count++;
                int tmp[11][11];
                for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        tmp[j][r - i - 1] = sticker[i][j];
                    }
                }

                for (int i = 0; i < r; i++)
                    fill(sticker[i], sticker[i] + c, 0);
                swap(r, c);

                for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        sticker[i][j] = tmp[i][j];
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1) ans++;
        }

    }
    cout << ans;
}