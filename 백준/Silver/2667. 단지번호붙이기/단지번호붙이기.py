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

visited = [[0] * n for _ in range(n)]
name = 1
cnt = [float('inf') for _ in range(10000)]
house = 0
for i in range(n):
    for j in range(n):
        if board[i][j] != 0 and not visited[i][j]:
            q = deque()
            q.append((i, j))
            visited[i][j] = 1
            house+=1
            while q:
                cur = q.popleft()
                for dir in range(4):
                    nx = cur[0] + dx[dir]
                    ny = cur[1] + dy[dir]
                    if nx < 0 or nx >= n or ny < 0 or ny >= n: continue
                    if visited[nx][ny]: continue
                    if board[nx][ny] == 0: continue
                    visited[nx][ny] = 1
                    house+=1
                    q.append((nx, ny))

            cnt[name] = house
            name+=1
            house = 0

print(name-1)
cnt.sort()
i=0
while cnt[i] != float('inf'):
    print(cnt[i])
    i+=1