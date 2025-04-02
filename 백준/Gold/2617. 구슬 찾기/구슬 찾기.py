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

h_adj = [[] for _ in range(n+1)]
l_adj = [[] for _ in range(n+1)]
for _ in range(m):
    u, v = list(map(int, sys.stdin.readline().strip().split()))
    h_adj[v].append(u)
    l_adj[u].append(v)

visited=[False for _ in range(n+1)] 
count = -1
def dfs(x, adj):
    global count
    #print(f"x: {x}")
    count+=1
    visited[x] = True
    for nxt in adj[x]:
        if not visited[nxt]:
            visited[nxt] = True
            dfs(nxt, adj)

ans = 0
for i in range(1, n+1):
    dfs(i, h_adj)
    #print(f"cnt: {count}")
    if count > n//2:
        ans+=1
    count = -1
    visited=[False for _ in range(n+1)] 
    dfs(i, l_adj)
    #print(f"cnt: {count}")
    if count > n//2:
            ans+=1
    count = -1
    visited=[False for _ in range(n+1)] 
print(ans)
        