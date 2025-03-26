import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

n = int(input())
stair = [0]
for _ in range(n):
    stair.append(int(sys.stdin.readline().strip()))
if n == 1:
    print(stair[1])
elif n == 2:
    print(stair[1] + stair[2])
else:
    dp = [[0 for _ in range(3)] for _ in range(n+1)]
    dp[1][1] = stair[1]
    dp[1][2] = 0
    dp[2][1] = stair[2]
    dp[2][2] = stair[2]+stair[1]

    for i in range(3, n+1):
        dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + stair[i]
        dp[i][2] = dp[i-1][1] + stair[i]

    print(max(dp[n][1], dp[n][2]))

