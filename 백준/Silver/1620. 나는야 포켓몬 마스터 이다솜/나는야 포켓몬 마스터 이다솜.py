import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

n, m = list(map(int, sys.stdin.readline().strip().split()))
numdogam = {}
pokemondogam = {}
for i in range(1, n+1):
    pokemon = sys.stdin.readline().strip()
    numdogam[i] = pokemon
    pokemondogam[pokemon] = i

for _ in range(m):
    tmp = sys.stdin.readline().strip()

    if tmp.isdigit():
        print(numdogam[int(tmp)])
    else:
        print(pokemondogam[tmp])