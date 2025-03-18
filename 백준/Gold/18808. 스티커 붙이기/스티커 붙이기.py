import math
import sys
import queue
import copy
from itertools import combinations

n, m, k = list(map(int, sys.stdin.readline().strip().split()))
notebook = [[0 for _ in range(41)] for _ in range(41)]

def isAvailable(x, y, sticker, r, c):
    for i in range(r):
        for j in range(c):
            if notebook[x+i][y+j] == 1 and sticker[i][j] == 1:
                return False
    return True

def rotate(sticker, r, c):
    tmp = [[0 for _ in range(11)] for _ in range(11)]
    for i in range(r):
        for j in range(c):
            tmp[j][r-i-1] = sticker[i][j]

    r, c = c, r
    for i in range(r):
        for j in range(c):
            sticker[i][j] = tmp[i][j]
    

for _ in range(k):
    r, c = list(map(int, sys.stdin.readline().strip().split()))
    sticker = [[0 for _ in range(11)] for _ in range(11)]
    for i in range(r):
        tmp = list(map(int, sys.stdin.readline().strip().split()))
        for j in range(c):
            sticker[i][j] = tmp[j]


    flag = False
    count = 0
    while count < 4:
        for i in range(n-r+1):
            for j in range(m-c+1):
                if isAvailable(i, j, sticker, r, c):
                    for k in range(r):
                        for l in range(c):
                            if sticker[k][l]:
                                notebook[i+k][j+l] = 1
         
                    flag = True
                    break
            if flag:
                break
        if flag:
            break

        rotate(sticker, r, c)
        r, c = c, r

        count += 1
ans = 0
for i in range(n):
    for j in range(m):
        if notebook[i][j] == 1:
            ans+=1
print(ans)