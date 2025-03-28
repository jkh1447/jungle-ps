import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

vertex = int(input())
edge = int(input())

adj = [[] for _ in range(vertex+1)]
pre = [0 for _ in range(vertex+1)]

for _ in range(edge):
    u, v, w = list(map(int, sys.stdin.readline().strip().split()))
    adj[u].append([w, v])

st, en = list(map(int, sys.stdin.readline().strip().split()))


d = [float('inf') for _ in range(vertex+1)]
d[st] = 0
pq = []
heapq.heappush(pq, (0, st))
while pq:
    dist, ver = heapq.heappop(pq)
    if d[ver] != dist: continue
    for nxt in adj[ver]:
        if d[nxt[1]] <= d[ver] + nxt[0]: continue
        d[nxt[1]] = d[ver] + nxt[0]
        heapq.heappush(pq, (d[nxt[1]], nxt[1]))
        pre[nxt[1]] = ver

print(d[en])

path = []
cur = en
while cur != st:
    path.append(cur)
    cur = pre[cur]
path.append(cur)
print(len(path))
for i in range(len(path)-1, -1, -1):
    print(path[i], end=' ')