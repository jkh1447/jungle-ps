import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

n, c = list(map(int, sys.stdin.readline().strip().split()))
lst = []
for _ in range(n):
    lst.append(int(sys.stdin.readline().strip()))

lst.sort()

st = 1
en = lst[-1]
result = 0
while st <= en:
    mid = (st+en)//2

    cur = 0
    cnt = 1
    for i in range(1, n):
        if lst[cur] + mid <= lst[i]:
            cnt += 1
            cur = i
    if cnt >= c:
        result = mid

        st = mid + 1
    else:
        en = mid - 1
print(result)