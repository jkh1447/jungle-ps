import math
import sys
from collections import deque

import copy
from itertools import combinations
sys.setrecursionlimit(100000)

n = int(input())

if n < 10:
    n *= 10
tmp = n
ans = 0
while True:
    if ans != 0 and tmp == n:
        break

    one = tmp % 10
    tmp //= 10
    ten = tmp % 10

    hap = ten + one

    tmp =  one * 10 + hap % 10

    ans += 1

print(ans)