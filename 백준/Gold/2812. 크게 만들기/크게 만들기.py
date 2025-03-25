import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

n, k = list(map(int, sys.stdin.readline().strip().split()))

num = sys.stdin.readline().strip()
s = []
cnt = 0
for i in range(n):

    while s and cnt < k and s[-1] < num[i]:
       s.pop()
       cnt+=1
    s.append(num[i])

if cnt < k:
    for _ in range(k-cnt):
        s.pop()

print(''.join(s))