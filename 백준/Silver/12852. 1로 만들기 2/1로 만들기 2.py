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
flag = False
if n == 1:
    flag = True
    print(0)
    print(1)

if not flag:
    d = [0 for _ in range(1000001)]
    path = [0 for _ in range(1000001)]
    for i in range(2, 1000001):
        if i % 2 == 0 and i % 3 == 0:
            min_idx = i-1
            min_val = d[i-1]
            if d[i//3] < min_val:
                min_val = d[i//3]
                min_idx = i//3
            if d[i//2] < min_val:
                min_val = d[i//2]
                min_idx = i//2
            if d[i-1] < min_val:
                min_val = d[i-1]
                min_idx = i-1
            d[i] = min_val + 1
            path[i] = min_idx
        elif i % 2 == 0:
            min_idx = i-1
            min_val = d[i-1]
            if d[i//2] < min_val:
                min_val = d[i//2]
                min_idx = i//2
            d[i] = min_val + 1
            path[i] = min_idx

        elif i % 3 == 0:
            min_idx = i-1
            min_val = d[i-1]
            if d[i//3] < min_val:
                min_val = d[i//3]
                min_idx = i//3
            d[i] = min_val + 1
            path[i] = min_idx
        else:
            d[i] = d[i-1] + 1
            path[i] = i-1
        if d[n] != 0:
            break
    print(d[n])
    print(n, end=' ')
    cur = path[n]
    while cur != 1:
        print(cur, end=' ')
        cur = path[cur]
    print(1)