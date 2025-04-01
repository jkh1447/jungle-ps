import math
import sys
from collections import deque

import copy
from itertools import combinations
sys.setrecursionlimit(100000)

n, m = list(map(int, sys.stdin.readline().strip().split()))

def func(k, path, visited):
    if len(path) == k:
        for i in path:
            print(i, end=" ")
        print()
        return
    for i in range(1, n+1):
        if not visited[i]:
            path.append(i)
            visited[i] = True
            func(k, path, visited)
            path.pop()
            visited[i] = False

func(m, [], [False for _ in range(n+1)])
