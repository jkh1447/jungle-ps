import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

n, k = list(map(int, sys.stdin.readline().strip().split()))

coins = []
for _ in range(n):
    coins.append(int(sys.stdin.readline().strip()))
ans=0
for i in range(n-1, -1, -1):
    if k // coins[i] == 0:
        continue
    ans += k // coins[i]
    k %= coins[i]
print(ans)
