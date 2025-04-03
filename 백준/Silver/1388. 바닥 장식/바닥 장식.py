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
    board.append(list(sys.stdin.readline().strip()))


cnt = 0
ans = 0
for i in range(n):
    cnt = 0
    for j in range(m):
        if board[i][j] == '|': 
            if cnt > 0:

                ans+=1
                cnt = 0
            else:
                continue
        else:
            cnt +=1
    if cnt > 0:
        ans+=1

cnt = 0

for j in range(m):
    cnt = 0
    for i in range(n):
        if board[i][j] == '-':
            if cnt > 0:
                ans+=1
                cnt = 0
            else:
                continue
        else:
            cnt+=1
    if cnt > 0:
        ans+=1

print(f"{ans}")