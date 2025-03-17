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
lst = []
t = int(input())
for i in range(t):
    n = int(sys.stdin.readline())

    half = n // 2
    a = half
    b = half
    for _ in range(half):
        if isPrime(a) and isPrime(b):
            print(a, b)
            break
        else:
            a -= 1
            b += 1

