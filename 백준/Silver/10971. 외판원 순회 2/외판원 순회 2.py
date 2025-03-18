import math
import sys
import queue
import copy
from itertools import combinations

n = int(input())
cost = []
min_val = sys.maxsize
def func(path, visited, hap):
    global min_val
    if len(path) == n:
        if cost[path[-1]][path[0]] != 0:
            hap += cost[path[-1]][path[0]]
            if min_val > hap:
                min_val = hap
            hap -= cost[path[-1]][path[0]]
            return
    for i in range(n):
        if not visited[i] and (len(path) == 0 or cost[path[-1]][i] != 0):
            visited[i] = True
            path.append(i)
            if len(path) > 1:
                hap += cost[path[-2]][path[-1]]
            func(path, visited, hap)
            if len(path) > 1:
                hap -= cost[path[-2]][path[-1]]
            path.pop()
            visited[i] = False

for _ in range(n):
    cost.append(list(map(int, sys.stdin.readline().strip().split())))

func([], [False for _ in range(n)], 0)
print(min_val)

