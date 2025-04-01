import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

n = int(input())

board = []
for _ in range(n):
    board.append(list(map(int, sys.stdin.readline().strip().split())))

def isFill(x, y, n):
    color = board[x][y]
    for i in range(x, x+n):
        for j in range(y, y+n):
            if board[i][j] != color:
                return 0
    return 1
blue = 0
white = 0
def func(x, y, n):
    global blue
    global white
    if not isFill(x, y, n):
        func(x, y, n//2)
        func(x + n//2, y, n//2)
        func(x, y + n//2, n//2)
        func(x + n//2, y + n//2, n//2)
    else:
        if board[x][y] == 1:
            blue+=1
        else:
            white+=1

func(0, 0, n)
print(white)
print(blue)