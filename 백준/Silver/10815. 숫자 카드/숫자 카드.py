import math
import sys
from collections import deque

import copy
from itertools import combinations
sys.setrecursionlimit(100000) 

n = int(input())
s = list(map(int, sys.stdin.readline().strip().split()))

m = int(input())
l = list(map(int, sys.stdin.readline().strip().split()))

sorted_s = sorted(s)

for target in l:
    st = 0
    en = n-1
    flag = False
    while st<=en:
        mid = (st+en)//2
        if sorted_s[mid] > target:
            en = mid-1
        elif sorted_s[mid] < target:
            st = mid + 1
        else:
            flag = True
            break
    if flag:
        print(1)
    else:
        print(0)
    
