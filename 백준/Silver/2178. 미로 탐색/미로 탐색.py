import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

n, m = list(map(int, sys.stdin.readline().strip().split()))

board = []
for _ in range(n):
    board.append(list(map(int, list(sys.stdin.readline().strip()))))
visited = [[0]*m for _ in range(n)]
q = deque()
q.append((0, 0))
visited[0][0] == 1

while q:
    cur = q.popleft()

    for dir in range(4):
        nx = cur[0] + dx[dir]
        ny = cur[1] + dy[dir]
        if nx < 0 or nx >= n or ny < 0 or ny >= m: continue
        if visited[nx][ny] or board[nx][ny] == 0: continue
        visited[nx][ny] = visited[cur[0]][cur[1]] + 1
        q.append((nx, ny))
print(visited[n-1][m-1] + 1)

