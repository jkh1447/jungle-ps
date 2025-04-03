import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

arr = []
n = int(input())
for _ in range(n):
    s, e = list(map(int, sys.stdin.readline().strip().split()))
    arr.append((s, e))
arr.sort(key=lambda x: (x[1], x[0]))
ans = 1


cur_end = arr[0][1]
for i in range(1, n):
    if arr[i][0] >= cur_end:
        ans+=1
        cur_end = arr[i][1]

print(ans)