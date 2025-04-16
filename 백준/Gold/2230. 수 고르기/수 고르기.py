import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

n, m = list(map(int, sys.stdin.readline().strip().split()))

arr = []
for i in range(n):
    arr.append(int(sys.stdin.readline().strip()))
arr.sort()
st = 0
en = 0
ans = float('inf')

while True:
    
    if st == n or en == n:
        break
    if arr[en] - arr[st] >= m:
        ans = min(ans, arr[en]-arr[st])
        #print(f"ans: {ans}")
        st += 1
        continue
    en +=1
print(ans)