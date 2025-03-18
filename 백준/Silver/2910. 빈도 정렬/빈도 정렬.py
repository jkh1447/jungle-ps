import math
import sys
import queue
import copy
from itertools import combinations

n, c = list(map(int, sys.stdin.readline().strip().split()))
dic = {}
lst = list(map(int, sys.stdin.readline().strip().split()))


for i in lst:
    if i not in dic:
        dic[i] = 1
    else:
        dic[i] += 1

sorted_dic = sorted(dic.items(), key=lambda x: x[1], reverse=True)


for i in sorted_dic:
    for j in range(i[1]):
        print(i[0], end=' ')