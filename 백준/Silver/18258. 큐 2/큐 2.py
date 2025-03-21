import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

MX = 1000005
dat = [0 for _ in range(2000005)]
head = 0
tail = 0

def push(x):
    global dat
    global head
    global tail
    dat[tail] = x
    tail +=1
def pop():
    global dat
    global head
    global tail
    head += 1
def front():
    global dat
    global head
    global tail
    return dat[head]
def back():
    global dat
    global head
    global tail
    return dat[tail-1]

n = int(input())

for _ in range(n):
    query = sys.stdin.readline().strip().split()

    q = query[0]
    if q == 'push':
        push(query[1])
    elif q == 'front':
        if tail - head == 0:
            print(-1)
        else: print(front())
    elif q == 'back':
        if tail - head == 0:
            print(-1)
        else: print(back())
    elif q == 'size':
        print(tail - head)
    elif q == 'pop':
        if tail - head == 0:
            print(-1)
        else:
            print(front())
            pop()
    else:
        print(0 if tail-head else 1)