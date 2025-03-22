import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

a, b, c = list(map(int, sys.stdin.readline().strip().split()))

def func(a, b, m):
    if b == 1:
        return a % m
    val = func(a, b//2, m)
    val = val * val % m
    if b%2 == 0:
        return val
    else:
        return (val * a) % m
    
print(func(a, b, c))