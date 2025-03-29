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
nums = list(map(int, sys.stdin.readline().strip().split()))
operators = list(map(int, sys.stdin.readline().strip().split()))

lst = []
for i in range(4):
    for j in range(operators[i]):
        if i == 0:
            lst.append('+')
        elif i == 1:
            lst.append('-')
        elif i == 2:
            lst.append('x')
        else:
            lst.append('/')
max_val = -(1 << 30)
min_val = float('inf')
def dfs(path, visited, c):
    global max_val
    global min_val
    if c == n-1:
        cur = nums[0]
        for i in range(len(path)):
            if path[i] == '+':
                cur += nums[i+1]
            elif path[i] == '-':
                cur -= nums[i+1]
            elif path[i] == 'x':
                cur *= nums[i+1]
            else:
                if cur < 0:
                    cur = -cur
                    cur //= nums[i+1]
                    cur = -cur
                else: 
                    cur //= nums[i+1]

        if cur > max_val:
            max_val = cur
        if cur < min_val:
            min_val = cur
        return

    for i in range(len(lst)):
        if visited[i]: continue
        visited[i] = 1
        path.append(lst[i])
        dfs(path, visited, c+1)
        visited[i] = 0
        path.pop()
dfs([], [0 for _ in range(n-1)], 0)

print(max_val)
print(min_val)