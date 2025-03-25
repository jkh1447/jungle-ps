import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)
arr = []

def func(st, en):
    if st == en:
        return arr[st]

    mid = (st+en)//2

    max_area = max(func(st, mid), func(mid+1, en))
 
     # 중앙을 포함하는 최대 넓이 계산
    left = mid
    right = mid
    min_height = arr[mid]
    max_area = max(max_area, min_height)

    while left > st or right < en:
        if right < en and (left == st or arr[right + 1] > arr[left - 1]):
            right += 1
            min_height = min(min_height, arr[right])
        else:
            left -= 1
            min_height = min(min_height, arr[left])

        max_area = max(max_area, min_height * (right - left + 1))

    return max_area
          


while True:
    arr = list(map(int, sys.stdin.readline().strip().split()))
    if arr == [0]:
        break
    arr = arr[1:]
    print(func(0, len(arr)-1))



