import math
import sys
import queue
import copy


n, m = list(map(int, sys.stdin.readline().split()))
a = list(map(int, sys.stdin.readline().split()))
b = list(map(int, sys.stdin.readline().split()))


merged_list = []
# for i in range(max(len(lst1), len(lst2))):

cur1 = 0
cur2 = 0
while(True):
    if cur1 == len(a):
        for i in range(cur2, len(b)):
            merged_list.append(b[i])
        break
    elif cur2 == len(b):
        for i in range(cur1, len(a)):
            merged_list.append(a[i])
        break

    if a[cur1] < b[cur2]:
        merged_list.append(a[cur1])
        cur1 += 1
    else:
        merged_list.append(b[cur2])
        cur2 += 1

for i in range(len(merged_list)):
    print(merged_list[i], end=' ')