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
    

    
    q = deque()

    colored = [-1 for _ in range(ver+1)]

    flag = False
    for i in range(1, v+1):
        if colored[i] == -1:
            q.append(i)
            colored[i] = 0
            while q:
                cur = q.popleft()
                for nxt in adj[cur]:
                    if colored[nxt] == -1:
                        colored[nxt] = 1 - colored[cur]
                        q.append(nxt)
                    else:
                        if colored[cur] == colored[nxt]:
                            flag = True
                            break
    
    
    if flag:
        print('NO')
    else:
        print('YES')