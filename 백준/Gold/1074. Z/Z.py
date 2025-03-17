import math
import sys
import queue
import copy

def func(n, r, c):
    if n == 1:
        if r == 0 and c == 0:
            return 0
        elif r == 0 and c == 1:
            return 1
        elif r == 1 and c == 0:
            return 2
        else:
            return 3
        
    half = 2**n >> 1
    if r < half and c < half:
        return func(n-1, r, c)
    elif r < half and c >= half:
        return func(n-1, r, c - half) + half * half
    elif r >= half and c < half:
        return func(n-1, r - half, c) + 2 * half * half
    else:
        return func(n-1, r - half, c - half) + 3 * half * half
    
n, r, c = list(map(int, sys.stdin.readline().split()))

print(func(n, r, c))