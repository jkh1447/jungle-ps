import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

k = int(input())

s = []

for _ in range(k):
    query = int(input())
    if query == 0:
        s.pop()
    else:
        s.append(query)

print(sum(s))