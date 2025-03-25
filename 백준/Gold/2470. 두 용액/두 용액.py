import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

n = int(input())
sol = list(map(int, sys.stdin.readline().strip().split()))
sol.sort()
ai=0
aj=0

min_val = (1 << 37)
for i in range(n-1):
    target = -sol[i]

    st = i+1
    en = n-1
    #print(f"{st}")
    while st<en:
        mid = (st+en)//2

        if sol[mid] >= target:
            en = mid
        else:
            st = mid + 1
    #print(sol)
    #print(f"i:{i}, {st} {sol[st]}")
    if abs(sol[st] - target) < min_val:
        min_val = abs(sol[st] - target)
        ai = i
        aj = st
        #print(f"minval: {min_val}")

    if i+1<st and abs(sol[st-1] - target) < min_val:
        min_val = abs(sol[st-1] - target)
        ai = i
        aj = st-1
        #print(f"minval: {min_val}")
print(f"{sol[ai]} {sol[aj]}")