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


for scene in range(1, t+1):
    n = int(input())
    k = int(input())
    p = [-1 for _ in range(n+1)]

    def find(x):
        if p[x] < 0:
            return x
        p[x] = find(p[x])
        return p[x]

    def uni(u, v):
        u = find(u)
        v = find(v)
        if u == v: return False
        p[v] = u
        return True
    
    for _ in range(k):
        u, v = list(map(int, sys.stdin.readline().strip().split()))
        uni(u, v)

    m = int(input())
    print(f"Scenario {scene}:")
    for _ in range(m):
        u, v = list(map(int, sys.stdin.readline().strip().split()))

        if find(u) == find(v):
            print(1)
        else:
            print(0)
    print()