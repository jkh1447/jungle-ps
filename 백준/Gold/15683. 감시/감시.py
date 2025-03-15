import math
import sys
import queue
import copy

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

r, c = list(map(int, sys.stdin.readline().split()))

board = [[0 for _ in range(9)] for _ in range(9)]
board2 = [[0 for _ in range(9)] for _ in range(9)]

for i in range(r):
    board[i] = list(map(int, sys.stdin.readline().split()))



def upd(board3, i, j, dir):
    dir %= 4
    while(True):
        i += dx[dir]
        j += dy[dir]
        # print(f"i, j: {i}, {j}")
        if i < 0 or i >= r or j < 0 or j >= c: return
        if board3[i][j] == 6: return
        if board3[i][j] != 0: continue
        board3[i][j] = 7
    


cctv = []

for i in range(r):
    for j in range(c):
        if 1<=board[i][j]<=5:
            cctv.append([i, j])

min_val = sys.maxsize
for i in range(1 << (2 * len(cctv))):
    for j in range(r):
        for k in range(c):
            board2[j][k] = board[j][k]

    cur = i
    for j in range(len(cctv)):
        dir = cur%4 # 한자리수 추출
        x = cctv[j][0]
        y = cctv[j][1]
        if board[x][y] == 1:

            upd(board2, x, y, dir)

        elif board[x][y] == 2:
            upd(board2, x, y, dir)
            upd(board2, x, y, dir + 2)
        elif board[x][y] == 3:
            upd(board2, x, y, dir)
            upd(board2, x, y, dir + 1)
            
        elif board[x][y] == 4:
            upd(board2, x, y, dir)
            upd(board2, x, y, dir + 1)
            upd(board2, x, y, dir + 2)
        else : 
            upd(board2, x, y, dir)
            upd(board2, x, y, dir + 1)
            upd(board2, x, y, dir + 2)
            upd(board2, x, y, dir + 3)

        cur //= 4
    count = 0
    for i in range(r):
        for j in range(c):
            if board2[i][j] == 0:
                count += 1
    # print()
    # for i in range(r):
    #     for j in range(c):
    #         print(board2[i][j], end=" ")
    #     print()
    if count < min_val:
        min_val = count

print(min_val)