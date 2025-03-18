import math
import sys
import queue
import copy
from itertools import combinations

arr = []
n, m = list(map(int, sys.stdin.readline().strip().split()))
for i in range(n):
    arr.append(list(map(int, sys.stdin.readline().strip().split())))

chicken = []
home = []

for i in range(n):
    for j in range(n):
        if arr[i][j] == 1:
            home.append([i, j])
        elif arr[i][j] == 2:
            chicken.append([i, j])


def getChickenDistance(chicken_list):
    hap = 0
    for i in range(len(home)):
        min_val = 10000
        for j in chicken_list:
            tmp = abs(home[i][0] - j[0]) + abs(home[i][1] - j[1])

            if tmp < min_val:
                min_val = tmp
        hap += min_val
    return hap




ans = 1000000
for i in combinations(chicken, m):
    tmp = getChickenDistance(i)
    if ans > tmp:
        ans = tmp
    
print(ans)
