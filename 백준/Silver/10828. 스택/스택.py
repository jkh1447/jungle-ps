import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

stack = [0 for _ in range(10005)]
cur = 0

def push(x):
    global cur
    global stack
    stack[cur] = x
    cur += 1

def pop():
    global cur
    global stack
    result = stack[cur-1]
    cur -=1
    return result

def top():
    global cur
    global stack
    return stack[cur-1]

n = int(input())

for _ in range(n):
    query = sys.stdin.readline().strip().split()
    if query[0] == 'push':
        push(int(query[1]))
    elif query[0] == 'top':
        if cur == 0:
            print(-1)
        else: print(top())
    elif query[0] == 'size':
        print(cur)
    elif query[0] == 'empty':
        print(1 if cur == 0 else 0 )
    else:
        if cur == 0:
            print(-1)
        else:
            print(pop())
            