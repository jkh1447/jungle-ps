import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
pre=[]

while True:
    try:
        pre.append(int(sys.stdin.readline()))
    except:
        break

def preorder(st, en):
    if en < st:
        return
    mid = en + 1
    for i in range(st+1, en+1):
        if pre[st] < pre[i]:
            mid = i
            break
    
    preorder(st+1, mid-1)
    preorder(mid, en)
    print(pre[st])
preorder(0, len(pre)-1)