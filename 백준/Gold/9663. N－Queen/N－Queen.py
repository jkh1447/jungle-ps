import math
import sys
import queue
import copy
from itertools import combinations

n = int(input())

lst1 = [False for _ in range(20)]
lst2 = [False for _ in range(50)]
lst3 = [False for _ in range(50)]
ans = 0
def func(r):
    global ans
    if r == n:
        ans+=1
    for i in range(n):
        if not lst1[i] and not lst2[r + i] and not lst3[r - i + n - 1]:
            lst1[i] = True
            lst2[r + i] = True
            lst3[r - i + n - 1] = True
            func(r+1)
            lst1[i] = False
            lst2[r + i] = False
            lst3[r - i + n - 1] = False

func(0)
print(ans)