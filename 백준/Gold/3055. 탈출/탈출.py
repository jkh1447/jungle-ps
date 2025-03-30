import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

r, c = list(map(int, sys.stdin.readline().strip().split()))
board = []

for _ in range(r):
    board.append(list(sys.stdin.readline().strip()))
s = []
d = []
w = []
w_dist = [[-1] * c for _ in range(r)]
s_dist = [[-1] * c for _ in range(r)]
for i in range(r):
    for j in range(c):
        if board[i][j] == 'S':
            s=(i, j)
        if board[i][j] == '*':
            w.append((i, j))
        if board[i][j] == 'D':
            d=(i, j)

q = deque()
for i in range(len(w)):
    q.append((w[i][0], w[i][1]))
    w_dist[w[i][0]][w[i][1]] = 0

while q:
    x, y = q.popleft()
    for dir in range(4):
        nx = x + dx[dir]
        ny = y + dy[dir]

        if nx < 0 or nx >= r or ny < 0 or ny >= c: continue
        if board[nx][ny] == '*' or w_dist[nx][ny] >= 0 or board[nx][ny] == 'X' or board[nx][ny] == 'D': continue
        w_dist[nx][ny] = w_dist[x][y] + 1
        q.append((nx, ny))

q.append(s)
s_dist[s[0]][s[1]] = 0
flag = False
while q:
    x, y = q.popleft()
    if x == d[0] and y == d[1]:
        flag = True
        print(s_dist[x][y])
        break
    for dir in range(4):
        nx = x + dx[dir]
        ny = y + dy[dir]

        if nx < 0 or nx >= r or ny < 0 or ny >= c: continue
        if board[nx][ny] == 'X' or board[nx][ny] == '*' or s_dist[nx][ny] >= 0: continue
        if w_dist[nx][ny] == -1 and s_dist[nx][ny] == -1:
            s_dist[nx][ny] = s_dist[x][y] + 1
            q.append((nx, ny)) 
            continue
        if s_dist[nx][ny] == -1 and s_dist[x][y] + 1 < w_dist[nx][ny] and w_dist[nx][ny] != -1:
            s_dist[nx][ny] = s_dist[x][y] + 1
            q.append((nx, ny))
if not flag:
    print('KAKTUS')

# for i in range(r):
#     for j in range(c):
#         print(w_dist[i][j], end=' ')
#     print()