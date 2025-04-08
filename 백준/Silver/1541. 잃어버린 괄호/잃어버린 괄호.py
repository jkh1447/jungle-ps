import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]



tmpexpr = list(sys.stdin.readline().strip().split('-'))

result = []
for expr in tmpexpr:
    tmp = map(int, expr.split('+'))
    result.append(sum(tmp))

ans = result[0]
for i in range(1, len(result)):
    ans -= result[i]
print(ans)
