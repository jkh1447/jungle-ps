import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

t = int(input())
for _ in range(t):
    ver, e = list(map(int, sys.stdin.readline().strip().split()))
    adj = [[] for _ in range(ver+1)]

    for _ in range(e):
        u, v = list(map(int, sys.stdin.readline().strip().split()))
        adj[u].append(v)
        adj[v].append(u)
    
    visited = [0 for _ in range(ver+1)] 

    q = deque()

    colored = [0 for _ in range(ver+1)]

    for i in range(1, v+1):
        if not visited[i]:
            q.append(i)
            visited[i] = 1
            colored[i] = 1
            while q:
                cur = q.popleft()
                cur_color = colored[cur]

                for nxt in adj[cur]:

                    if not visited[nxt]:

                        visited[nxt] = 1
                        if cur_color == 1:
                            colored[nxt] = 2
                        else:
                            colored[nxt] = 1
                        q.append(nxt)

    visited = [0 for _ in range(ver+1)]

    flag = False
    for i in range(1, v+1):
        if not visited[i]:
            q.append(i)
            visited[i] = 1
            while q:
                cur = q.popleft()
                cur_color = colored[cur]
                for nxt in adj[cur]:
                    if cur_color == colored[nxt]:
                        flag = True
                        break
                    if not visited[nxt]:
                        visited[nxt] = 1
                        q.append(nxt)
    
    if flag:
        print('NO')
    else:
        print('YES')