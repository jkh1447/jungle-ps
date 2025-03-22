import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

n = int(input())
a = list(map(int, sys.stdin.readline().strip().split()))

lst = [a[0]]
for i in range(1, n):
    if a[i] > lst[-1]:
        lst.append(a[i])
    else:
        st = 0
        en = len(lst)
        while st < en:
            mid = (st+en)//2

            if lst[mid] >= a[i]:
                en = mid
            else:
                st = mid + 1
        lst[st] = a[i]

print(len(lst))