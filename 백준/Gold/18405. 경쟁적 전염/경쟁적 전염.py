import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

n, k = list(map(int, sys.stdin.readline().strip().split()))

board = []

for _ in range(n):
    board.append(list(map(int, sys.stdin.readline().strip().split())))

s, a, b = list(map(int, sys.stdin.readline().strip().split()))

dist = [[-1] * n for _ in range(n)]

q = deque()
tmp = []
for i in range(n):
    for j in range(n):
        if board[i][j] != 0:
            tmp.append((board[i][j], i, j))
            dist[i][j] = 0
tmp.sort()
for i in tmp:
    q.append(i)

while q:
    v, x, y = q.popleft()
    if dist[x][y] == s:
        break
    for dir in range(4):
            nx = x + dx[dir]
            ny = y + dy[dir]
            if nx < 0 or nx >= n or ny < 0 or ny >= n: continue
            if board[nx][ny] != 0 or dist[nx][ny] >= 0: continue
            dist[nx][ny] = dist[x][y] + 1
            board[nx][ny] = v
            q.append((v, nx, ny))

print(board[a-1][b-1])
