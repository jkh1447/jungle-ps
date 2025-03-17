import math
import sys
import queue
import copy

n = int(sys.stdin.readline())

arr = [0 for _ in range(10001)]

for _ in range(n):
    arr[int(sys.stdin.readline())] += 1

for i in range(1, 10001):
    if arr[i]:
        for _ in range(arr[i]):
            print(i)