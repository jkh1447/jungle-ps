import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

n, c = list(map(int, sys.stdin.readline().strip().split()))
homes = []

for _ in range(n):
    homes.append(int(sys.stdin.readline().strip()))

homes.sort()

max = homes[-1]

st = 0
en = max
ans = 0
while st <= en:
    mid = (st+en)//2
    cnt = 1
    cur = 0
    for i in range(1, n):
        if homes[i] - homes[cur] >= mid: #전부 다 mid값보다 크거나 같은 차이로 공유기 설치에 성공하면 인접한 두 공유기의 거리가 최소한 mid이상이 된다
            cnt += 1
            cur = i
    if cnt >= c:
        ans = mid
        st = mid + 1
    else: 
        en = mid - 1

print(ans)