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
board=[]
for i in range(n):
    board.append(list(map(int, sys.stdin.readline().strip().split())))


dist = [[0] * n for _ in range(n)]
dist[0][0] = 1
for i in range(n):
    # print(f"i: {i}")
    for j in range(n):
        if i == n-1 and j == n-1:
            continue
        # print(f"board[i][j]: {board[i][j]}")
        if dist[i][j] > 0:
            nx = i + board[i][j]
            ny = j + board[i][j]
            if nx < n:
                dist[nx][j] += dist[i][j]
            if ny < n:
                dist[i][ny] += dist[i][j]
            # print('--------')
            # for j in range(n):
            #     for k in range(n):
            #         print(dist[j][k], end=' ')
            #     print()
print(dist[n-1][n-1])