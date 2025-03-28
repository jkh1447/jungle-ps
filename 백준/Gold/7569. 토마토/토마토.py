import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)
dx = [1, 0, -1, 0, 0, 0]
dy = [0, 1, 0, -1, 0, 0]
dz = [0, 0, 0, 0, -1, 1]

m, n, h = list(map(int, sys.stdin.readline().strip().split()))
board=[]

for i in range(h):
    tmp = []
    for j in range(n):
        tmp.append(list(map(int, sys.stdin.readline().strip().split())))
    board.append(tmp)
# print()
# for i in range(h):
#     for j in range(n):
#         for k in range(m):
#             print(board[i][j][k], end=" ")
#         print()
#     print()
# print()


dist = [[[-1 for _ in range(m)] for _ in range(n)] for _ in range(h)]

q = deque()

for i in range(h):
    for j in range(n):
        for k in range(m):
            if board[i][j][k] == 1:
                q.append([i, j, k])
                dist[i][j][k] = 0

while q:
    cur = q.popleft()
    for dir in range(6):
        nz = cur[0] + dz[dir]
        nx = cur[1] + dx[dir]
        ny = cur[2] + dy[dir]

        if nx < 0 or nx >= n or ny < 0 or ny >= m or nz < 0 or nz >= h:
            continue
        if board[nz][nx][ny] == 1 or board[nz][nx][ny] == -1:
            continue
        if dist[nz][nx][ny] >= 0:
            continue
        dist[nz][nx][ny] = dist[cur[0]][cur[1]][cur[2]] + 1
        q.append([nz, nx, ny])

ans = 0
flag = False
for i in range(h):
    for j in range(n):
        for k in range(m):
            if dist[i][j][k] == -1 and board[i][j][k] == 0:
                flag = True
                break
            ans = max(dist[i][j][k], ans)     


if flag:
    print(-1)
else:
    print(ans)
