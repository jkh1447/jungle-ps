import math
import sys
import queue
import copy
from itertools import combinations

def permutation(arr, k):
    def func(path, visited):
        if len(path) == k:
            result.append(path[:])
            return
        for i in range(len(arr)):
            if not visited[i]:
                visited[i] = True
                path.append(arr[i])
                func(path, visited)
                visited[i] = False
                path.pop()
    result = []
    func([], [False for _ in range(len(arr))])
    return result
n = int(input())
arr = list(map(int, sys.stdin.readline().strip().split()))
ans = 0
for lst in permutation(arr, len(arr)):
    hap = 0
    for i in range(len(lst) - 1):
        hap += abs(lst[i] - lst[i+1])
    if hap > ans:
        ans = hap
print(ans)