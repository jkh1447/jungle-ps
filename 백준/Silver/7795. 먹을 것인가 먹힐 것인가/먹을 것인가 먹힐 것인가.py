import math
import sys
import queue
import copy
from itertools import combinations

t= int(input())
for _ in range(t):
    n, m = list(map(int, sys.stdin.readline().strip().split()))

    A = list(map(int, sys.stdin.readline().strip().split()))
    B = list(map(int, sys.stdin.readline().strip().split()))
    A.sort(reverse=True)
    B.sort(reverse=True)

    bidx = 0
    ans = 0
    for i in range(len(A)):
        while bidx != len(B)-1 and B[bidx] >= A[i]:
            bidx += 1
        if B[bidx] < A[i]:
            ans += len(B) - bidx
        
    print(ans)