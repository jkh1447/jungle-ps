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
ai = 0
aj = 0
min_val = (1 << 37)
for i in range(n-1):
    target = -sol[i]
    st = i+1
    en = n-1
    #en을 n-1까지하면 target넘버가 가장 큰 수일 경우 n-1을 반환
    while st < en:
        mid=(st+en)//2

        if sol[mid] >= target:
            en = mid
        else:
            st = mid + 1
    # i<=st면 i == st가 돼서 x,
    # i가 n-1이 되면 st가 n이 되고 while문은 스킵되면서 st = n이 된다. 이 경우는 고려하지 않아도 된다
    if i+1 <= st and abs(sol[st] + sol[i]) < min_val:
        min_val = abs(sol[st] + sol[i])
        ai = i
        aj = st
    # i+1 == st이면 st-1이 i가 되버리기 때문
    if i+1 <= st - 1  and abs(sol[st-1]+sol[i]) < min_val:
        min_val = abs(sol[st-1] + sol[i])
        ai = i
        aj = st - 1
print(f"{sol[ai]} {sol[aj]}")

