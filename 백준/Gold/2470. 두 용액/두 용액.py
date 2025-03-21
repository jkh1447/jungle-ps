import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

n = int(input())

lst = list(map(int, sys.stdin.readline().strip().split()))
lst.sort()

ai = 0
aj = 0
min_val = float('inf')

for i in range(n):
    target = -lst[i]

    st = i+1
    en = n-1

    while st < en:
        mid = (st+en)//2
        if lst[mid] >= target:
            en = mid
        else:
            st = mid + 1
    
    if i+1 <= st and st < n and abs(lst[st] + lst[i]) < min_val:
        min_val = abs(lst[st] + lst[i])
        ai = i
        aj = st
    
    if i+1 <= st - 1 and st - 1 < n and abs(lst[st-1] + lst[i]) < min_val:
        min_val = abs(lst[st-1] + lst[i])
        ai = i
        aj = st-1

print(f"{lst[ai]} {lst[aj]}")