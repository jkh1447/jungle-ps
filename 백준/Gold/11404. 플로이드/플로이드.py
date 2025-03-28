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

for _ in range(m):
    a, b, c = list(map(int, sys.stdin.readline().strip().split()))
    V[a][b] = min(c, V[a][b])

for i in range(1, n+1):
        for j in range(1, n+1):
            if i == j: 
                V[i][j] = 0

for mid in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            V[i][j] = min(V[i][j], V[i][mid]+V[mid][j])

for i in range(1, n+1):
        for j in range(1, n+1):
            if V[i][j] == float('inf'):
                print(0, end=' ')
            else: print(V[i][j], end=' ')
        print()
print()