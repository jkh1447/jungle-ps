import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

n = int(input())
lst1 = list(map(int, sys.stdin.readline().strip().split()))
m = int(input())
lst2 = list(map(int, sys.stdin.readline().strip().split()))
lst1.sort()

def bs(arr, num):
    st = 0
    en = n-1
    while st <= en:
        mid = (st+en)//2
        if arr[mid] > num:
            en = mid - 1
        elif arr[mid] < num:
            st = mid + 1
        else:
            return 1
    return 0
for i in range(m):
    print(bs(lst1, lst2[i]))
        