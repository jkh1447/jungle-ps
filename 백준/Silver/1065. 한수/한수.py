import math
import sys
import queue

import copy
from itertools import combinations

n = int(input())

ans = 0
if n <= 99:
    print(n)
else:
    for i in range(100, n+1):
        i = str(i)
        if int(i[0]) - int(i[1]) == int(i[1]) - int(i[2]):
            ans+=1
    print(99 + ans)
            