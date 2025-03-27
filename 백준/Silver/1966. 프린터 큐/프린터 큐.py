import math
import sys
from collections import deque

import copy
from itertools import combinations
sys.setrecursionlimit(100000) 

t = int(input())

def findMax(q):
    max_val = 0
    for i in range(len(q)):
        if q[i][1] > max_val:
            max_val = q[i][1]
    return max_val
for _ in range(t):
    n, m = list(map(int, sys.stdin.readline().strip().split()))
    doc = deque()
    tmp = []

    tmp = list(map(int, sys.stdin.readline().strip().split()))
    for i in range(n):
        doc.append([i, tmp[i]])
    cnt = 0
    while doc:

        if doc[0][1] < findMax(doc):
            doc.append(doc.popleft())
        else:
            cnt+=1
            if doc[0][0] == m:
                print(cnt)
                break
            doc.popleft()
