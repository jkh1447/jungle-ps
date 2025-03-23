import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

def dist(p1, p2):
    return (p1[0]-p2[0]) ** 2 + (p1[1]-p2[1]) ** 2

def closest_pair(sorted_by_x):
    if len(sorted_by_x) <= 3:

        min_dist = math.inf
        for i in range(len(sorted_by_x)):
            for j in range(i+1, len(sorted_by_x)):
                min_dist = min(min_dist, dist(sorted_by_x[i], sorted_by_x[j]))
        return min_dist
    
    mid = len(sorted_by_x) // 2
    mid_x = sorted_by_x[mid][0]
    left_part = sorted_by_x[:mid]
    right_part = sorted_by_x[mid:]

    d = min(closest_pair(left_part), closest_pair(right_part))

    candidates = []
    for point in sorted_by_x:
        if (point[0] - mid_x) ** 2 <= d:
            candidates.append(point)

    candidates.sort(key=lambda x: x[1])

    for i in range(len(candidates)):
        for j in range(i+1, len(candidates)):
            if (candidates[i][1] - candidates[j][1]) ** 2 >= d:
                break
            d = min(d, dist(candidates[i], candidates[j]))
    return d 

n = int(sys.stdin.readline().strip())
points = [tuple(map(int, sys.stdin.readline().split())) for _ in range(n)]

# x좌표 기준 정렬 후 분할 정복 수행
points.sort()
print(closest_pair(points))