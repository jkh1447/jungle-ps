import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

m, n, l = list(map(int, sys.stdin.readline().strip().split()))
pad = list(map(int, sys.stdin.readline().strip().split()))
animals = []
pad.sort()
for _ in range(n):
    animals.append(list(map(int, sys.stdin.readline().strip().split())))
ans = 0
for i in range(n):
    anim = animals[i]
    st = 0
    en = m

    while st < en:
        mid = (st+en)//2

        if pad[mid] >= anim[0]:
            en = mid
        else:
            st = mid + 1

    if st != m and st >= 0 and abs(anim[0] - pad[st]) >= abs(pad[st-1] - anim[0]):
        st = st-1
    if st == m:
        if abs(pad[st-1] - anim[0]) + anim[1] <= l:
            ans+=1
    elif st < 0:
        if abs(pad[st+1] - anim[0]) + anim[1] <= l:
            ans+=1
    elif abs(pad[st] - anim[0]) + anim[1] <= l:
        ans+=1

print(ans)
