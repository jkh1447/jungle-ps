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
state = [-1]
state += list(map(int, sys.stdin.readline().strip()))
adj = [[] for _ in range(n+1)]
for _ in range(n-1):
    u, v = list(map(int, sys.stdin.readline().strip().split()))
    adj[u].append(v)
    adj[v].append(u)
visited = [0 for _ in range(n+1)]
ans = 0
def dfs(x, n):
    global ans
    if state[x] == 1 and n != 0:
        ans+=1
        return
    visited[x] = 1
    for nxt in adj[x]:
        if not visited[nxt]:
            dfs(nxt, n+1)

for i in range(1, n+1):
    visited = [0 for _ in range(n+1)]
    if state[i] == 1:
        dfs(i, 0)
print(ans)