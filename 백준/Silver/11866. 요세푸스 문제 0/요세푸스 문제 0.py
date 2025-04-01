import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

n, k = list(map(int, sys.stdin.readline().strip().split()))


q = deque()
for i in range(1, n+1):
    q.append(i)
print('<', end='')
while len(q)!=0:
    for i in range(k-1):
        q.append(q.popleft())
    tmp = q.popleft()
    if len(q) == 0:
        print(tmp, end='')
    else:
        print(tmp, end=', ')

print('>')