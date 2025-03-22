import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

n = int(input())

s = []

for _ in range(n):
    s.append(int(sys.stdin.readline()))
ans = 0
max_height = 0
for _ in range(n):
    if max_height < s[-1]:
        max_height = s.pop()
        ans+=1
    else:
        s.pop()

print(ans)