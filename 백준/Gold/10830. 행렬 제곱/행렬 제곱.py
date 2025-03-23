import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

n, b = list(map(int, sys.stdin.readline().strip().split()))

mat = []
for _ in range(n):
    mat.append(list(map(int, sys.stdin.readline().strip().split())))

def multi(mat1, mat2):
    result = []
    for i in range(len(mat1)):
        result.append([])
        for j in range(len(mat2)):
            tmp = 0
            for l in range(len(mat1)):
                tmp += mat1[i][l] * mat2[l][j]
            tmp %= 1000
            result[i].append(tmp)
    return result

def func(mat, n):
    if n == 1:
        for i in range(len(mat)):
            for j in range(len(mat)):
                mat[i][j] %= 1000
        return mat
    matrix = func(mat, n//2)
    matrix = multi(matrix, matrix)
    if n % 2 == 0:
        return matrix
    else:
        return multi(matrix, mat)
ans = func(mat, b)    
for i in range(n):
    for j in range(n):
        print(ans[i][j], end=' ')
    print()