import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

ver = int(input())
e = int(input())
adj = [[] for _ in range(ver+1)]
for _ in range(e):
    u, v = list(map(int, sys.stdin.readline().strip().split()))
    adj[u].append(v)
    adj[v].append(u)

q = deque()
q.append(1)
visited = [0 for _ in range(ver+1)]
visited[1] = 1
ans = 0
while q:
    cur = q.popleft()
    for nxt in adj[cur]:
        if visited[nxt]: continue
        visited[nxt]=1
        ans +=1
        q.append(nxt)
print(ans)
