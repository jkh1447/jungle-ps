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
m = int(input())

V = [[float('inf')] * (n+1) for _ in range(n+1)]
nxt = [[0] * (n+1) for _ in range(n+1)]
for _ in range(m):
    a, b, c = list(map(int, sys.stdin.readline().strip().split()))
    V[a][b] = min(c, V[a][b])
    nxt[a][b] = b

for i in range(1, n+1):
        for j in range(1, n+1):
            if i == j: 
                V[i][j] = 0

for mid in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            if V[i][j] > V[i][mid]+V[mid][j]:
                V[i][j] = V[i][mid]+V[mid][j]
                nxt[i][j] = nxt[i][mid]
            

for i in range(1, n+1):
        for j in range(1, n+1):
            if V[i][j] == float('inf'):
                print(0, end=' ')
            else: print(V[i][j], end=' ')
        print()

for i in range(1, n+1):
    for j in range(1, n+1):
        if V[i][j] == 0 or V[i][j] == float('inf'):
            print(0)
            continue
        
        path = []
        cur = i
        while cur != j:
            path.append(cur)
            cur = nxt[cur][j]
        path.append(j)
        print(len(path),end=' ')
        for num in path:
            print(num, end=' ')
        print()
