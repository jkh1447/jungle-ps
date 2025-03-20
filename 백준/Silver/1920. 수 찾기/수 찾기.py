import math
import sys
from collections import deque

import copy
from itertools import combinations
sys.setrecursionlimit(100000)

n = int(input())
A = list(map(int, sys.stdin.readline().strip().split()))
m = int(input())
B = list(map(int, sys.stdin.readline().strip().split()))
A.sort()


def binarySearch(arr, num):

    st = 0
    en = n-1

    while st <= en:
        mid = (st+en) // 2
        if num == arr[mid]:
            return 1
        if num > arr[mid]:
            st = mid + 1
        else:
            en = mid - 1

    return 0

for b in B:
    print(binarySearch(A, b))