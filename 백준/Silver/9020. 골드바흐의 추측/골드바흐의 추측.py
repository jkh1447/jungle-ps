import math
import sys
import queue
import copy
from itertools import combinations

def isPrime(n):
    if n == 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

t = int(input())

for _ in range(t):
    n = int(input())
    a = n // 2
    b = n // 2
    for _ in range(n//2):
        if isPrime(a) and isPrime(b):
            print(f"{a} {b}")
            break
        else:
            a -= 1
            b += 1