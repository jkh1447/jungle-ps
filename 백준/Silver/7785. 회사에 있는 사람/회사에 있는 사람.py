import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

n = int(input())
attendance = {}
for _ in range(n):
    name, state = sys.stdin.readline().strip().split()
    if not name in attendance:
        attendance[name] = state
    else:
        if state == 'leave':
            del attendance[name]


sorted_atten = {k: attendance[k] for k in sorted(attendance, reverse=True)}

for key, val in sorted_atten.items():
    print(key)