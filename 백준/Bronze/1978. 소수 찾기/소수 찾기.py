import math
import sys
import queue
import copy
from itertools import combinations

def isPrime(n):
    if n == 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n%i ==0:
            return False
    return True
n = int(sys.stdin.readline().strip())
lst = list(map(int, sys.stdin.readline().strip().split()))


ans = 0
for i in lst:
    if isPrime(i):
        ans+=1
print(ans)