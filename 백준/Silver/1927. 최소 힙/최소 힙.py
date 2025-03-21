import math
import sys
from collections import deque

import copy
from itertools import combinations
sys.setrecursionlimit(100000)


heap = [0 for _ in range(100005)]
sz = 0

def push(x):
    global sz
    global heap
    sz += 1
    heap[sz] = x

    idx = sz
    while idx != 1:
        par = idx//2
        if heap[par] <= heap[idx]: break
        heap[par], heap[idx] = heap[idx], heap[par]
        idx = par

def top():
    return heap[1]

def pop():
    global sz
    global heap
    heap[1] = heap[sz]
    sz -= 1
    idx = 1
    while 2 * idx <= sz: #리프노드를 벗어나면 종료
        lc = 2*idx
        rc = 2*idx+1
        min_child = lc
        if rc<=sz and heap[rc] < heap[lc]: # 리프노드가 아니라면 오른쪽 자식은 있을수도있고 없을수도있다
            min_child = rc
        if heap[idx] <= heap[min_child]:
            break
        heap[idx], heap[min_child] = heap[min_child], heap[idx]
        idx = min_child
        

n = int(sys.stdin.readline().strip())

for _ in range(n):
    tmp = int(sys.stdin.readline().strip())

    if tmp > 0:
        push(tmp)
    else:
        if sz == 0:
            print(0)
            continue
        print(top())
        pop()