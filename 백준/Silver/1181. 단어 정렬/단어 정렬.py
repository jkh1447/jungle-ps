import math
import sys

n = int(input())
lst = []
for i in range(n):
    lst.append(sys.stdin.readline().strip())

lst = list(set(lst))
lst.sort()
lst.sort(key=len)

for i in range(len(lst)):
    print(lst[i])


