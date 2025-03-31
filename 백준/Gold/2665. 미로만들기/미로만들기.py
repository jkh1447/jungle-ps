import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

n = int(input())
board = []
for _ in range(n):
    board.append(list(map(int, list(sys.stdin.readline().strip()))))

visited = [[False] * n for _ in range(n)]
dist = [[-1] * n for _ in range(n)]
dist[0][0] = 0

q = deque()
q.append((0, 0))

while q:
    x, y = q.popleft()
    for dir in range(4):
        nx = x + dx[dir]
        ny = y + dy[dir]

        if nx < 0 or nx >= n or ny < 0 or ny >= n: continue
        if dist[nx][ny] >= 0: continue
        if board[nx][ny] == 1:
            dist[nx][ny] = dist[x][y]
            q.appendleft((nx, ny))
        if board[nx][ny] == 0:
            dist[nx][ny] = dist[x][y] + 1
            q.append((nx, ny))

print(dist[n-1][n-1])