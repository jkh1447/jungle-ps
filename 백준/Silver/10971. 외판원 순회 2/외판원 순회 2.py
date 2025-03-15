import math
import sys

n = int(input())
lst = []
for i in range(n):
    lst.append(list(map(int, sys.stdin.readline().split())))

min_value = sys.maxsize
hap = 0
def func(path, visited, hap):
    global min_value
    # print(visited)
    # print(path)
    if len(path) == n:
        if lst[path[-1]][path[0]] == 0:
            return
        hap += lst[path[-1]][path[0]]
        if min_value > hap:
            min_value = hap
        hap -= lst[path[-1]][path[0]]
        return
    
    for i in range(n):
        
        if not visited[i] and (len(path) == 0 or lst[path[-1]][i] != 0):
            visited[i] = True
            path.append(i)
            if len(path) > 1:
                hap += lst[path[-2]][path[-1]]
            func(path, visited, hap)
            if len(path) > 1:
                hap -= lst[path[-2]][path[-1]]
            visited[i] = False
            path.pop()
            

func([], [False for _ in range(n)], 0)
print(min_value)