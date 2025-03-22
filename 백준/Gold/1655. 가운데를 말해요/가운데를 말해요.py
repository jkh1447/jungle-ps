import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

max_heap = []
min_heap = []
n = int(input())
for _ in range(n):
    tmp = int(sys.stdin.readline().strip())

    if not max_heap or -max_heap[0] >= tmp:
        heapq.heappush(max_heap, -tmp)
        if len(max_heap) > len(min_heap) + 1:
            heapq.heappush(min_heap, -heapq.heappop(max_heap))
    else:
        heapq.heappush(min_heap, tmp)
        if len(max_heap) < len(min_heap):
            heapq.heappush(max_heap, -heapq.heappop(min_heap))
    print(-max_heap[0])