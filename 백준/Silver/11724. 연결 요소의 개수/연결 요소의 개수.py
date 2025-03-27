import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

n, m = list(map(int, sys.stdin.readline().strip().split()))

vertices = [[] for _ in range(n+1)]

for _ in range(m):
    u, v = list(map(int, sys.stdin.readline().strip().split()))
    vertices[u].append(v)
    vertices[v].append(u)
visited = [0 for _ in range(n+1)]

ans = 0
for i in range(1, n+1):
    q = deque()
    if not visited[i]:
        q.append(i)
        visited[i] = 1

        while q:
            cur = q.popleft()
            # print(f"{cur} ->", end=' ')
            for next in vertices[cur]:
                if not visited[next]:
                    visited[next] = 1
                    q.append(next)
        ans+=1
print(ans)