import math
import sys
import queue
import copy


n = int(sys.stdin.readline().strip())

cost = []

for _ in range(n):
    cost.append(list(map(int, sys.stdin.readline().strip().split())))

min = sys.maxsize

def tsp(visited, path, hap):
    global min

    if len(path) == n:
        if cost[path[-1]][path[0]] == 0:
            return
        hap += cost[path[-1]][path[0]]
        if hap < min:
            min = hap
        hap -= cost[path[-1]][path[0]]
        return
    for i in range(n):
        if not visited[i] and (len(path) == 0 or cost[path[-1]][i] != 0):
            visited[i] = True
            path.append(i)
            if len(path) > 1:
                hap += cost[path[-2]][path[-1]]
            tsp(visited, path, hap)
            if len(path) > 1:
                hap -= cost[path[-2]][path[-1]]
            visited[i] = False
            path.pop()
tsp([False for _ in range(n)], [], 0)
print(min)