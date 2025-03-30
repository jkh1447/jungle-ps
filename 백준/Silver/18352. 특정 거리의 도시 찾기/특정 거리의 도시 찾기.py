import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

n, m, k, x = list(map(int, sys.stdin.readline().strip().split()))
adj = [[] for _ in range(n+1)]
for _ in range(m):
    u, v = list(map(int, sys.stdin.readline().strip().split()))
    adj[u].append(v)

q = deque()
q.append(x)
d = [-1 for _ in range(n+1)]
d[x] = 0
while q:
    cur = q.popleft()
    for nxt in adj[cur]:
        if d[nxt] == -1:
            d[nxt] = d[cur] + 1
            q.append(nxt)

flag = False
for i in range(1, n+1):
    if d[i] == k:
        flag = True
        print(i)

if not flag:
    print(-1)