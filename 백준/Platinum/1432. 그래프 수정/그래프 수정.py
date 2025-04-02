import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

n = int(input())
v = [[0 for _ in range(n+1)]]
for _ in range(n):
    v.append([0] + list(map(int, list(sys.stdin.readline().strip()))))

deg = [0 for _ in range(n+1)]

for i in range(1, n+1):
    for j in range(1, n+1):
        if v[i][j] != 0:
            deg[i] += 1
# out degree를 셈
            

# for i in range(1, n+1):
#     for j in range(1, n+1):
#         print(v[i][j], end=' ')
#     print()
flag = False

pq = []
for i in range(1, n+1):
    if deg[i] == 0:
        heapq.heappush(pq, -i)

if not pq:
    flag = True
result = []
while pq:
    cur = -heapq.heappop(pq)
    result.append(cur)
    for i in range(1, n+1):
        if v[i][cur] != 0:
            deg[i] -= 1
            if deg[i] == 0:
                heapq.heappush(pq, -i)
result.append(0)
result = result[::-1]


if flag:
    print(-1)
else:
    tmp = [0 for _ in range(n+1)]
    for i in range(1, n+1):
        tmp[result[i]] = i
    
    for i in range(1, n+1):
        print(tmp[i], end=' ')