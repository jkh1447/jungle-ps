import math
import sys
from collections import deque

import copy
from itertools import combinations

t = int(input())
lst = [0 for _ in range(12)]
lst[1] = 1
lst[2] = 2
lst[3] = 4
for _ in range(t):
    n = int(input())
    if n <=3:
        print(lst[n])
        continue
    for i in range(4, n+1):
        lst[i] = lst[i-1] + lst[i-2] + lst[i-3]
    print(lst[n])
    