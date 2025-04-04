import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

n = int(input())
arr=[]
for _ in range(n):
    arr.append(int(sys.stdin.readline().strip()))
arr.sort()

d=[0 for _ in range(n)]
for i in range(1, n+1):
    d[n-i] = arr[n-i] * i

print(max(d))  