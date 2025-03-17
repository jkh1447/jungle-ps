import math
import sys
import queue
import copy

def func(n, a, b):
    if n == 1:
        print(f"{a} {b}")
        return

    func(n-1, a, 6-a-b)
    print(f"{a} {b}")
    func(n-1, 6-a-b, b)

n = int(sys.stdin.readline())

print(f"{(1 << n) - 1}")
if n <= 20:
    func(n, 1, 3)