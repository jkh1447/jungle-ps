import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

n, m, s = list(map(int, sys.stdin.readline().strip().split()))

lst = [[] for _ in range(n+1)]

for _ in range(m):
    u, v = list(map(int, sys.stdin.readline().strip().split()))
    lst[u].append(v)
    lst[v].append(u)
visited = [0 for _ in range(n+1)]

for i in range(1, n+1):
    lst[i].sort()

def dfs(s):
    visited[s] = 1
    print(s, end=' ')
    for next in lst[s]:
        if not visited[next]:
            dfs(next)
dfs(s)

print()

visited = [0 for _ in range(n+1)]
q = deque()
q.append(s)
visited[s] = 1
while q:
    cur = q.popleft()
    print(cur, end=' ')
    for next in lst[cur]:
        if not visited[next]:
            visited[next] = 1
            q.append(next)