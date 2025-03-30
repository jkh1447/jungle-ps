import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

n, k = list(map(int, sys.stdin.readline().strip().split()))
coins = []
for _ in range(n):
    coins.append(int(sys.stdin.readline().strip()))

dist = [-1 for _ in range(20000)]
q = deque()
q.append(0)
dist[0] = 0
flag = False
while q:
    if dist[k] != -1:
        print(dist[k])
        flag = True
        break
    cur = q.popleft()
    
    for coin in coins:
        if cur + coin > 10000 or dist[cur + coin] >= 0: continue
        dist[cur + coin] = dist[cur] + 1
        q.append(cur+coin)
if not flag: print(dist[k])