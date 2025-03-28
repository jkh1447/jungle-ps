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
dist = [[0] * 301 for _ in range(301)]
board = [[0] * 301 for _ in range(301)]
for i in range(n):
    board[i] = list(map(int, sys.stdin.readline().strip().split()))

q = deque()
ans = 0
while True:
    for i in range(n):
        dist[i] = [0] * m

    tmp = [[0] * 301 for _ in range(301)]
    for i in range(n):
        for j in range(m):
            if board[i][j] != 0:
                for dir in range(4):
                    nx = i + dx[dir]
                    ny = j + dy[dir]
                    if 0 <= nx < n and 0 <= ny < m and board[nx][ny] == 0:
                        tmp[i][j] += 1
    for i in range(n):
        for j in range(m):
            if board[i][j] != 0:
                board[i][j] -= tmp[i][j]
                if board[i][j] < 0:
                    board[i][j] = 0 

    ans+=1
    cnt = 0
    flag = False

    for i in range(n):
        for j in range(m):
            if board[i][j] > 0 and dist[i][j] == 0:
                cnt +=1
                q.append((i, j))
                dist[i][j] = 1

                while q:
                    x, y = q.popleft()

                    for dir in range(4):
                        nx = x + dx[dir]
                        ny = y + dy[dir]
                        if 0 <= nx < n and 0 <= ny < m and dist[nx][ny] == 0 and board[nx][ny] > 0:
                            dist[nx][ny] = 1
                            q.append((nx, ny))
    if cnt >= 2:
        break
    elif cnt == 0:
        flag = True
        break
    

if flag:
    print(0)
else:
    print(ans)