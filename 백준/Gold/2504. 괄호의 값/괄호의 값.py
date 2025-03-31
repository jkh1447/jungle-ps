import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

lst = list(sys.stdin.readline().strip())

s=[]
flag = False
ans = 0
cur = 1
for i in range(len(lst)):
    if lst[i]=='(':
        cur *= 2
        s.append('(')
    elif lst[i]=='[':
        cur *= 3
        s.append('[')
    elif lst[i]==')':
        if len(s) == 0 or s[-1] != '(': 
            flag = True
            break
        if lst[i-1] == '(':
            ans += cur
            s.pop()
        else:
            s.pop()
        cur //= 2
    else:
        if len(s) == 0 or s[-1] != '[': 
            flag = True
            break
        if lst[i-1] == '[':
            ans += cur
            s.pop()
        else:
            s.pop()
        cur //= 3

if flag or len(s) != 0:
    print(0)
else:
    print(ans)
