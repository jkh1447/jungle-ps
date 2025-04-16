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


    dp = [0 for i in range(101)]

    dp[1] = 1
    dp[2] = 1
    dp[3] = 1
    dp[4] = 2
    dp[5] = 2
    dp[6] = 3

    for i in range(7, n+1):
        dp[i] = dp[i-1] + dp[i-5]
    print(dp[n])