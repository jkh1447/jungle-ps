import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

V, E = list(map(int, sys.stdin.readline().strip().split()))

adj = [[] for _ in range(V+1)]

for _ in range(E):
    u, v, cost = list(map(int, sys.stdin.readline().strip().split()))
    adj[u].append([cost, v])
    adj[v].append([cost, u])

chk = [0 for _ in range(V+1)]
pq = []

chk[1] = 1
for nxt in adj[1]:
    heapq.heappush(pq, (nxt[0], 1, nxt[1]))
ans = 0
cnt = 0
while cnt < V-1:
    cost, a, b = heapq.heappop(pq)
    if chk[b]:
        continue
    cnt+=1
    ans += cost
    chk[b] = 1
    for nxt in adj[b]:
        if not chk[nxt[1]]:
            heapq.heappush(pq, (nxt[0], b, nxt[1]))
print(ans)