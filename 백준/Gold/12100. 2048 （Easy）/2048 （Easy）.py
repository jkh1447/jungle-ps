import math
import sys
import queue
import copy

n = int(sys.stdin.readline().strip())
arr = [[0 for _ in range(21)] for _ in range(21)]
arr2 = []
for i in range(n):
    lst = list(map(int, (sys.stdin.readline().strip().split())))
    for j in range(n):
        arr[i][j] = lst[j]
 
def rotate():
    tmp_arr=[[0 for _ in range(21)] for _ in range(21)]
    for i in range(n):
        for j in range(n):
            tmp_arr[j][n-i-1] = arr2[i][j]
    for i in range(n):
        for j in range(n):
            arr2[i][j] = tmp_arr[i][j]

def tilt(dir):
    for _ in range(dir):
        rotate()

    for i in range(n):
        tmp = [0 for _ in range(n)]
        tidx = 0

        for j in range(n):
            if arr2[i][j] == 0: continue
            if tmp[tidx] == 0:
                tmp[tidx] = arr2[i][j]
            elif tmp[tidx] == arr2[i][j]:
                tmp[tidx] *= 2
                tidx += 1
            else:
                tidx +=1
                tmp[tidx] = arr2[i][j]
        for j in range(n):
            arr2[i][j] = tmp[j]
    

# tilt()
# for i in range(n):
#     for j in range(n):
#         print(arr[i][j], end=' ')
#     print()
max = 0
for i in range(1024):
    brute = i
    arr2 = [row[:] for row in arr]
    for _ in range(5):
        dir = brute % 4
        brute //= 4
        tilt(dir)
        
    i_max = 0
    for i in range(n):
        for j in range(n):
            if arr2[i][j] > i_max:
                i_max = arr2[i][j]
    if max < i_max:
        max = i_max
print(max)
