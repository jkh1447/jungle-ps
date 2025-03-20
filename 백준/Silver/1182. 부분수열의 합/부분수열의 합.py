import math
import sys
from collections import deque

import copy
from itertools import combinations

n, s = list(map(int, sys.stdin.readline().strip().split()))

lst = list(map(int, sys.stdin.readline().strip().split()))
ans = 0
for i in range(1, n+1):
    for combi in combinations(lst, i):
        if sum(combi) == s:
            ans += 1
print(ans)