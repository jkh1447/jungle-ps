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
ans = 0
state = [-1]
state += list(map(int, sys.stdin.readline().strip()))
adj = [[] for _ in range(n+1)]
for _ in range(n-1):
    u, v = list(map(int, sys.stdin.readline().strip().split()))
    adj[u].append(v)
    adj[v].append(u)
    if state[u] == 1 and state[v] == 1:
        ans+=2
visited = [0 for _ in range(n+1)]


cnt = 0
def dfs(x):
    global cnt
    visited[x] = 1
    for nxt in adj[x]:
        if state[nxt] == 1 and not visited[nxt]:
            cnt+=1
        elif state[nxt] == 0 and not visited[nxt]:
            visited[nxt] = 1
            dfs(nxt)


for i in range(1, n+1):
    if state[i] == 0 and not visited[i]:
        dfs(i)
        ans += cnt * (cnt-1)
        cnt = 0

print(ans)