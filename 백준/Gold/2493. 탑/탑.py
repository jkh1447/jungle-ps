import math
import sys
import queue

import copy
from itertools import combinations

n = int(input())
lst = list(map(int, sys.stdin.readline().strip().split()))

s = []
s.append([0, 1 << 27])

for i in range(n):
    while True:
        if lst[i] < s[-1][1]:
            print(s[-1][0], end=" ")
            break
        else:
            s.pop()
    s.append([i+1, lst[i]])
