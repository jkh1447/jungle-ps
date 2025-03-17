import math
import sys
import queue
import copy

a = 0
b = 0

a = int(sys.stdin.readline())
b = int(sys.stdin.readline())

three = (a * (b % 10))
b //= 10
four = (a * (b % 10))
b //= 10
five = (a * (b % 10)) 

print(three)
print(four)
print(five)
print(three + four*10 + five*100)