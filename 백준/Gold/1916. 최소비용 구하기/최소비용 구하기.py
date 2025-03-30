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

adj = [[] for _ in range(n+1)]
for _ in range(m):
    u, v, cost = list(map(int, sys.stdin.readline().strip().split()))
    adj[u].append((cost, v))
s, e = list(map(int, sys.stdin.readline().strip().split()))
pq = []
d = [float('inf') for _ in range(n+1)]
d[s] = 0
heapq.heappush(pq, (0, s))

while pq:
    c, v = heapq.heappop(pq)
    if d[v] != c: continue
    for nxt in adj[v]:
        if d[nxt[1]] <= d[v] + nxt[0]: continue
        d[nxt[1]] = d[v] + nxt[0]
        heapq.heappush(pq, (d[nxt[1]], nxt[1]))

print(d[e])