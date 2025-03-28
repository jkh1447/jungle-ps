import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

vertex, edge = list(map(int, sys.stdin.readline().strip().split()))
k = int(input())

adj = [[] for _ in range(vertex+1)]
for _ in range(edge):
    u, v, w = list(map(int, sys.stdin.readline().strip().split()))
    adj[u].append([w, v])

d = [float('inf') for _ in range(vertex+1)]
d[k] = 0
pq = []
heapq.heappush(pq, (0, k))
while pq:
    dist, ver = heapq.heappop(pq)
    if d[ver] != dist: continue
    for nxt in adj[ver]:
        if d[nxt[1]] <= d[ver] + nxt[0]: continue
        d[nxt[1]] = d[ver] + nxt[0]
        heapq.heappush(pq, (d[nxt[1]], nxt[1]))
for i in range(1, vertex+1):
    if d[i] == float('inf'):
        print('INF')
    else: 
        print(d[i])