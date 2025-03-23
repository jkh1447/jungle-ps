import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

n = int(input())
k = int(input())
board = [[0 for _ in range(n+1)] for _ in range(n+1)]


for _ in range(k):
    si, sj = list(map(int, sys.stdin.readline().strip().split()))
    board[si][sj] = 2

l = int(input())
q = deque()
for _ in range(l):
    q.append(sys.stdin.readline().strip().split())


dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

time = 0
snake = deque()
snake.append([1, 1])
idx = 1

while True:

    cur = snake[0]
    board[cur[0]][cur[1]] = 1
    time += 1
    nx = cur[0] + dx[idx]
    ny = cur[1] + dy[idx]


    if nx < 1 or nx > n or ny < 1 or ny > n:
        break
    if board[nx][ny] == 1: break

    #사과가 아닐경우
    if board[nx][ny] != 2:
        tail = snake.pop()
        board[tail[0]][tail[1]] = 0
    
    snake.appendleft([nx, ny])

    if len(q) != 0:
        dir = q.popleft()
        if int(dir[0]) == time:
            if dir[1] == 'D':
                idx = (idx - 1) % 4
            else:
                idx = (idx + 1) % 4
        else:
            q.appendleft(dir)
print(time)