import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

n = int(input())
red = [0]
green = [0]
blue = [0]

for i in range(n):
    r, g, b = list(map(int, sys.stdin.readline().strip().split()))
    red.append(r)
    green.append(g)
    blue.append(b)
dp = [[0 for _ in range(4)] for _ in range(n+1)]
dp[1][1]=red[1]
dp[1][2]=green[1]
dp[1][3]=blue[1]

for i in range(2, n+1):
    dp[i][1] = min(dp[i-1][2], dp[i-1][3]) + red[i]
    dp[i][2] = min(dp[i-1][1], dp[i-1][3]) + green[i]
    dp[i][3] = min(dp[i-1][1], dp[i-1][2]) + blue[i]
print(min(dp[n][1], dp[n][2], dp[n][3]))