import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

t = int(input())
for _ in range(t):
    n = int(input())
    coins = list(map(int, sys.stdin.readline().strip().split()))
    m = int(input())
    d = [0 for _ in range(m+1)]
    d[0] = 1
    for coin in coins:
        for i in range(coin, m+1):
            d[i] += d[i - coin]
    print(d[m])