import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

heap = [0 for _ in range(100001)]
sz = 0
def push(x):
    global heap
    global sz
    sz+=1
    heap[sz] = x
    idx = sz
    while idx != 1:
        par = idx//2
        if heap[par] > heap[idx]: break
        heap[par], heap[idx] = heap[idx], heap[par]
        idx = par

def top():
    global heap
    global sz
    return heap[1]

def pop():
    global heap
    global sz    
    heap[1] = heap[sz]
    sz -=1

    idx = 1
    while 2 * idx <= sz:
        lc = 2 * idx
        rc = 2 * idx + 1
        max_child = lc
        if rc <= sz and heap[lc] < heap[rc]:
            max_child = rc
        if heap[max_child] <= heap[idx]: break
        heap[max_child], heap[idx] = heap[idx], heap[max_child]
        idx = max_child

        
n = int(input())

for _ in range(n):
    q = int(sys.stdin.readline().strip())
    if q == 0:
        if sz == 0:
            print(0)
        else:
            print(heap[1])
            pop()
    else:
        push(q)