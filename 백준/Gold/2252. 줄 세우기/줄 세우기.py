import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

n, m = list(map(int, sys.stdin.readline().strip().split()))

deg = [0 for _ in range(n+1)]

adj = [[] for _ in range(n+1)]

for _ in range(m):
    u, v = list(map(int, sys.stdin.readline().strip().split()))
    adj[u].append(v)


for i in range(1, n+1):
    for j in range(len(adj[i])):
        deg[adj[i][j]] += 1

q = deque()
for i in range(1, n+1):
    if deg[i] == 0:
        q.append(i)
result = []
while q:
    cur = q.popleft()
    result.append(cur)
    for nxt in adj[cur]:
        deg[nxt]-=1
        if deg[nxt] == 0:
            q.append(nxt)
for i in range(len(result)):
    print(result[i], end=" ")