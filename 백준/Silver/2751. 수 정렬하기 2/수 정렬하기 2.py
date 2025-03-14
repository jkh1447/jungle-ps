import math

n = int(input())
lst = []

for i in range(n):
    tmp = int(input())
    lst.append(tmp)

lst.sort()

for i in range(len(lst)):
    print(lst[i])