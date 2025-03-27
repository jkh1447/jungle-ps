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


p = [0 for _ in range(n+1)]
def dfs(x):
    for nxt in adj[x]:
        if p[x] == nxt: continue
        p[nxt] = x
        dfs(nxt)
dfs(1)

for i in range(2, n+1):
    print(p[i])