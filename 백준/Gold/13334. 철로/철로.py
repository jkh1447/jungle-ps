import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

n = int(input())
lst = []
for _ in range(n):
    h, o = list(map(int, sys.stdin.readline().strip().split()))
    if h<o:
        lst.append([h, o])
    else:
        lst.append([o, h])

lst.sort(key=lambda x: x[1])
d = int(input())
heap = []
ans = 0
for i in range(n):
    heapq.heappush(heap, lst[i][0])
    while heap and heap[0] < lst[i][1] - d:
        heapq.heappop(heap)
    if ans < len(heap):
        ans = len(heap)

print(ans)