import math
import sys
from collections import deque

import copy
from itertools import combinations
sys.setrecursionlimit(100000)

n = int(input())
board = [[False for _ in range(2200)] for _ in range(2200)]

def func(x, y, n):
    if n == 1:
        board[x][y] = True
        return
    for i in range(3):
        for j in range(3):
            if i == 1 and j == 1: continue
            func(x + i * n//3, y + j * n//3, n//3)

func(0, 0, n)
for i in range(n):
    for j in range(n):
        if board[i][j]:
            print('*',end='')
        else:
            print(' ',end='')
    print()