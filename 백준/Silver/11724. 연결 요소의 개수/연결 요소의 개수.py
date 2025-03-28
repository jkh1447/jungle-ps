import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

n, m = list(map(int, sys.stdin.readline().strip().split()))

adj = [[] for _ in range(n+1)]

for i in range(m):
    u, v = list(map(int, sys.stdin.readline().strip().split()))
    adj[u].append(v)
    adj[v].append(u)
visited = [0 for _ in range(n+1)]
ans = 0
for i in range(1, n+1):
    if not visited[i]:
        ans += 1
        q = deque()
        q.append(i)
        visited[i] = 1

        while q:
            cur = q.popleft()
            for nxt in adj[cur]:
                if not visited[nxt]:
                    visited[nxt] = 1
                    q.append(nxt)
print(ans)