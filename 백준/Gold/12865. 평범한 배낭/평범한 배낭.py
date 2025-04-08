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
items = [[0, 0]]
for _ in range(n):
    items.append(list(map(int, sys.stdin.readline().strip().split())))

d = [[0 for _ in range(k+1)] for _ in range(n+1)]

for i in range(1, n+1):
    for j in range(1, k+1):
        if j >= items[i][0]:
            d[i][j] = max(d[i-1][j-items[i][0]] + items[i][1], d[i-1][j])
        else:
            d[i][j] = d[i-1][j]

print(d[n][k])