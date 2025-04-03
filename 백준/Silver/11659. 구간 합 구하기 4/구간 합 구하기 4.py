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

arr = list(map(int, sys.stdin.readline().strip().split()))
d = [0 for _ in range(n+1)]
d[1] = arr[0]
for i in range(2, n+1):
    d[i] = d[i-1] + arr[i-1]

for _ in range(m):
    a, b = list(map(int, sys.stdin.readline().strip().split()))
    print(d[b] - d[a-1])