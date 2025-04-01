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
p = [-1 for _ in range(n+1)]
def find(x):
    if p[x] < 0:
        return x
    p[x] = find(p[x])
    return p[x]

def uni(u, v):
    u = find(u)
    v = find(v)
    if u == v:
        return False
    p[v] = u
    return True

for _ in range(m):
    q, a, b = list(map(int, sys.stdin.readline().strip().split()))
    if q == 0:
        uni(a, b)
    else:
        if find(a) == find(b):
            print("YES")
        else:
            print("NO")