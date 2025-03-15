import math
import sys
import queue
sys.setrecursionlimit(100000)
n = int(input())
lst = []
max_value = 0
for i in range(n):
    tmp = list(map(int, sys.stdin.readline().split()))
    if max_value < max(tmp):
        max_value = max(tmp)
    lst.append(tmp)

dx = [1, 0, -1, 0]
dy = [0, 1, 0 , -1]

max = 0
for i in range(max_value, -1, -1):
    visited = [[False for _ in range(n)] for _ in range(n)]
    result = 0
    for j in range(n):
        for k in range(n):
            if lst[j][k] > i and not visited[j][k]:
                result += 1
                q = queue.Queue()
                q.put([j, k])
                visited[j][k] = True
                while(not q.empty()):
                    cur = q.get()
                    #print(f"{cur[0]}, {cur[1]} ->")
                    for dir in range(4):
                        nx = cur[0] + dx[dir]
                        ny = cur[1] + dy[dir]
                        if nx < 0 or nx >= n or ny < 0 or ny >= n: continue
                        if visited[nx][ny] or lst[nx][ny] <= i: continue
                        visited[nx][ny] = True
                        q.put([nx, ny])
    
    if max < result:
        max = result
                    

print(max)