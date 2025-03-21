import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

t = int(input())

for _ in range(t):
    parenthesis = list(sys.stdin.readline().strip())
    
    s = []

    flag = False
    for i in parenthesis:
        #print(s)
        if i == '(':
            s.append('(')
        else:
            if len(s) == 0 or s[-1] != '(':
                flag = True
                break
            else:
                s.pop()
    
    if flag or len(s) > 0:
        print('NO')
    else: print('YES')
