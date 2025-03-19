import math
import sys
import queue

import copy
from itertools import combinations

bracket = sys.stdin.readline().strip()
s = []
hap = 0
cur = 1
flag = False
for i in range(len(bracket)):
    if bracket[i] == '(':
        s.append('(')
        cur *= 2
    elif bracket[i] == '[':
        s.append('[')
        cur *= 3
    elif bracket[i] == ')':
        if len(s) == 0 or s[-1] != '(':
            flag = True
            break
        if bracket[i-1] == '(':
            hap += cur
        cur = cur // 2
        s.pop()
    else:
        if len(s) == 0 or s[-1] != '[':
            flag = True
            break
        if bracket[i-1] == '[':
            hap += cur
        cur = cur // 3
        s.pop()

if flag or len(s)!=0: 
    print(0)
else: print(hap)