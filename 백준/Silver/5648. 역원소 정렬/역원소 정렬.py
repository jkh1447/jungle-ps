import math
import sys
import queue
import copy
from itertools import combinations

tmp = list(sys.stdin.readline().strip().split())
lst = tmp[1:]
n = int(tmp[0])

while len(lst) != n:
    tmp1 = list(sys.stdin.readline().strip().split())
    lst = lst + tmp1

def reverse_num(str):
    str_list = list(str)
    l = 0
    r = len(str_list)-1
    for _ in range(len(str_list)//2):
        str_list[l], str_list[r] = str_list[r], str_list[l]
        l += 1
        r -= 1
    return ''.join(str_list)

for i in range(len(lst)):
    lst[i] = int(reverse_num(lst[i]))

lst.sort()
for i in range(len(lst)):
    print(lst[i])