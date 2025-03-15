import math
import sys
import queue
import copy

n = int(sys.stdin.readline())
lst = []
for i in range(n):
    lst.append(int(sys.stdin.readline()))

lst.sort()


max_count = 0
max_val = -(1 << 62) -1
count = 1

for i in range(1, n):
    if(lst[i-1] == lst[i]): count+=1
    else:
        if count > max_count:
            max_count = count
            max_val = lst[i-1]
        count = 1

if count > max_count:
    max_val = lst[n-1]

print(max_val)