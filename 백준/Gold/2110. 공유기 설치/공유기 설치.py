import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

n, c = list(map(int, sys.stdin.readline().strip().split()))
homes = []

for _ in range(n):
    homes.append(int(sys.stdin.readline().strip()))

homes.sort()
max_val = homes[-1]

st = 0
en = max_val
ans = 0
while st<=en:
    mid = (st+en)//2

    cnt = 1
    current = homes[0]
    for i in range(1, n):
        if (homes[i] - current) >= mid:
            cnt += 1
            current = homes[i]

    if cnt >= c:
        ans = mid
        st = mid + 1
    else:
        en = mid - 1
print(ans)
