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

d = [[0] * (n+1) for _ in range(n+1)]

adj = [[] for _ in range(n+1)]
deg = [0 for _ in range(n+1)]
for _ in range(m):
    x, y, k = list(map(int, sys.stdin.readline().strip().split()))
    adj[y].append(x)
    d[x][y] = k

for i in range(1, n+1):
    for nxt in adj[i]:
        deg[nxt] += 1
q = deque()

basic = []

for i in range(1, n+1):
    if deg[i] == 0:
        q.append(i)
        basic.append(i)

result = []
while q:
    cur = q.popleft()
    result.append(cur)
    for nxt in adj[cur]:
        deg[nxt] -= 1
        if deg[nxt] == 0:
            q.append(nxt)

for i in result:
    for j in range(n+1):
        if d[i][j] != 0:
            for k in range(n+1):
                if k not in basic: continue
                d[i][k] += d[j][k] * d[i][j]

for i in basic:
    print(f"{i} {d[n][i]}")