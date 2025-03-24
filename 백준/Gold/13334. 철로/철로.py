import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

n = int(input())
ho = []
for _ in range(n):
    a, b = list(map(int, sys.stdin.readline().strip().split()))
    ho.append([min(a, b), max(a, b)])
ho.sort(key=lambda x: x[1])
d = int(input())


pq = []

max_val = 0
for i in range(len(ho)):
    heapq.heappush(pq, ho[i][0])
    while len(pq) != 0 and pq[0] < ho[i][1] - d: heapq.heappop(pq)
    max_val = max(max_val, len(pq))
print(max_val)
