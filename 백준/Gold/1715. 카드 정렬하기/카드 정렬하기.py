import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

q = []

n = int(input())

for _ in range(n):
    heapq.heappush(q, int(sys.stdin.readline().strip()))

hap = 0
while len(q) > 1:
    a = heapq.heappop(q)
    b = heapq.heappop(q)
    hap += a + b
    heapq.heappush(q, a+b)
print(hap)