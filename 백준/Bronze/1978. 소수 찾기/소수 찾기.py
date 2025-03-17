import math
import sys
import queue
import copy

def isPrime(n):
    if n == 1: return False
    for i in range(2, n):
        if n % i == 0:
            return False
    return True

n = int(input())
ans = 0
lst = list(map(int, sys.stdin.readline().split()))
for i in lst:
    if isPrime(i):
        ans += 1
print(ans)