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

lst = list(map(int, sys.stdin.readline().strip().split()))

d = [1 for _ in range(n)]

for i in range(n):
    for j in range(i):
        if lst[j] < lst[i]:
            d[i] = max(d[i], d[j] + 1)

                
print(max(d))