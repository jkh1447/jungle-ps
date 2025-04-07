import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

a = [''] + list(sys.stdin.readline().strip())
b = [''] + list(sys.stdin.readline().strip())
max_len = max(len(a), len(b))
d = [[0] * max_len for _ in range(max_len)]


for i in range(1, len(a)):
    for j in range(1, len(b)):
        if a[i] == b[j]:
            d[i][j] = d[i-1][j-1] + 1
        else:
            d[i][j] = max(d[i][j-1], d[i-1][j])


print(d[len(a)-1][len(b)-1])