import math
import sys
from collections import deque

import copy
from itertools import combinations

t = int(input())

NOT_VISITED = 0
CYCLE_IN = -1

for _ in range(t):

    

    n = int(input())
    lst = [0] + list(map(int, sys.stdin.readline().strip().split()))
    # -1: not visit -2: not cycle in -3: cycle in
    state = [0 for _ in range(n+1)]

    def run(i):
        cur = i
        while True:

            state[cur] = i 
            cur = lst[cur]
            if state[cur] == i:
                while state[cur] != CYCLE_IN:
                    state[cur] = CYCLE_IN
                    cur = lst[cur]
                return
            elif state[cur] != 0: return

    for i in range(1, n+1):
        if state[i] == NOT_VISITED:
            run(i)
    ans = 0
    for i in range(1, n+1):
        if state[i] != CYCLE_IN:
            ans+=1
    print(ans)
