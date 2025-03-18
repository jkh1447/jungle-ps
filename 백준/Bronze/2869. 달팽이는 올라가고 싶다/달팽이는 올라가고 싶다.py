import math
import sys
import queue
import copy
from itertools import combinations

a, b, v = list(map(int, sys.stdin.readline().strip().split()))

if (v-a) % (a-b) == 0:
    print((v-a) // (a-b) + 1)
else:
    print((v-a) // (a-b) + 2)