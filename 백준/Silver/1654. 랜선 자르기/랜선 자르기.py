import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

k, n = list(map(int, sys.stdin.readline().strip().split()))

lans = []

for _ in range(k):
    tmp = int(sys.stdin.readline().strip())
    lans.append(tmp)

max_val = max(lans)

st = 1
en = max_val
ans = 0
while st<=en:
    mid = (st+en)//2
    cnt = 0
    for i in range(k):
        cnt += lans[i] // mid
    if cnt >= n:
        ans = mid
        st = mid + 1
    else:
        en = mid - 1
print(ans)