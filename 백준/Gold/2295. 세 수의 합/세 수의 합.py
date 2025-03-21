import math
import sys
from collections import deque

import copy
from itertools import combinations
sys.setrecursionlimit(100000)

n = int(input())
lst = []
for _ in range(n):
    lst.append(int(input()))
lst.sort()
two = []

def bs(arr, num):
    st = 0
    en = len(arr)-1

    while st <= en:
        mid = (st+en) // 2
        if arr[mid] > num:
            en = mid - 1
        elif arr[mid] < num:
            st = mid + 1
        else:
            return 1
    return 0

for i in range(n):
    for j in range(i, n):
        two.append(lst[i] + lst[j])
two.sort()

max_val = 0

flag = False
for i in range(n-1, -1, -1):
    for j in range(0, i):
        if bs(two, lst[i]-lst[j]):
            print(lst[i])
            flag = True
            break
    if flag:
        break



