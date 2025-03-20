import math
import sys
from collections import deque

import copy
from itertools import combinations
sys.setrecursionlimit(100000)

n = int(input())
lst1 = list(map(int, sys.stdin.readline().strip().split()))
lst = sorted(lst1)
lst.append((1 << 37) + 1)
new_lst = []
for i in range(1, n+1):
    if lst[i-1] == lst[i]:
        continue
    new_lst.append(lst[i-1])

def lower_bound(arr, num):
    st = 0
    en = len(arr)

    while st < en:
        mid = (st+en) // 2
        if arr[mid] >= num:
            en = mid
        else:
            st = mid + 1
    return st
for i in range(n):
    print(lower_bound(new_lst, lst1[i]), end=' ')

