import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

n, m = list(map(int, sys.stdin.readline().strip().split()))
trees = list(map(int, sys.stdin.readline().strip().split()))

max_val = max(trees)

def bs():
    st = 0
    en = max_val
    result = 0
    while st <= en:
        mid = (st+en)//2
        hap = 0
        for i in trees:
            if i > mid:
                hap += i - mid
        if hap >= m:
            result = mid
            st = mid + 1
        elif hap < m:
            en = mid - 1
        
    return result


print(bs())