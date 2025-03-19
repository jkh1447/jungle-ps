import math
import sys
from collections import deque

import copy
from itertools import combinations

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
board = []
n, m = list(map(int, sys.stdin.readline().strip().split()))
for _ in range(n):
    board.append(list(map(int, input().strip())))

visited=[[[-1] * m for _ in range(n)] for _ in range(2)]
q = deque()
visited[0][0][0] = 0
q.append((0, 0, 0))
flag = False
while len(q) != 0:
    broken, x, y = q.popleft()
    if x == n-1 and y == m-1:
        if visited[broken][x][y] != -1:
            print(visited[broken][x][y] + 1)
            flag = True
        break

    for dir in range(4):
        
        nx = x + dx[dir]
        ny = y + dy[dir]

        if nx < 0 or nx >= n or ny < 0 or ny >= m:
            continue
        if broken == 0 and board[nx][ny] == 1 and visited[broken][nx][ny] == -1:
            visited[1][nx][ny] = visited[0][x][y] + 1
            q.append((1, nx, ny))
            continue
        if board[nx][ny] == 0 and visited[broken][nx][ny] == -1:
            visited[broken][nx][ny] = visited[broken][x][y] + 1
            q.append((broken, nx, ny))
            continue
if not flag:
    print(-1)