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
 
    left = mid-1
    right = mid+1
    cur_height = arr[mid]
    if max_area < cur_height: max_area=cur_height
    while left >= st or right <= en:

        if left >= st and arr[left] == 0 and right > en:
            break
        if right <= en and arr[right] == 0 and left < st:
            break
        if left < st or arr[left] == 0:
            if arr[right] <= cur_height:
                cur_height = arr[right]
            right+=1
        elif right > en or arr[right] == 0 :
            if arr[left] <= cur_height:
                cur_height = arr[left]
            left-=1
        elif arr[left] > arr[right]:
            if arr[left] <= cur_height:
                cur_height = arr[left]
            left-=1
        else:
            if arr[right] <= cur_height:
                cur_height = arr[right]
            right+=1
        
        if max_area < cur_height * (right-left-1):
            max_area = cur_height * (right-left-1)
          
    return max_area

while True:
    arr = list(map(int, sys.stdin.readline().strip().split()))
    if arr == [0]:
        break
    arr = arr[1:]
    print(func(0, len(arr)-1))



