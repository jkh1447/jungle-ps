import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

n = int(input())
adj = [[] for _ in range(n+1)]
for i in range(n-1):
    u, v = list(map(int, sys.stdin.readline().strip().split()))
    adj[u].append(v)
    adj[v].append(u)

q = deque()
q.append(1)
p = [0 for _ in range(n+1)]
while q:
    cur = q.popleft()
    for nxt in adj[cur]:
        if p[cur] == nxt: continue
        p[nxt] = cur
        q.append(nxt)

for i in range(2, n+1):
    print(p[i])