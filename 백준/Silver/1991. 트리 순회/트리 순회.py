import math
import sys
from collections import deque
import heapq
import copy
from itertools import combinations
sys.setrecursionlimit(100000)

n = int(input())
lc = [0 for _ in range(n+1)]
rc = [0 for _ in range(n+1)]

for _ in range(n):
    node, l, r = sys.stdin.readline().strip().split()
    if l != '.': lc[ord(node) - ord('A') + 1] = ord(l)-ord('A')+1
    if r != '.': rc[ord(node) - ord('A') + 1] = ord(r)-ord('A')+1

def preorder(root):
    print(chr(root + ord('A') - 1), end='')
    if lc[root] != 0: preorder(lc[root])
    if rc[root] != 0: preorder(rc[root])

def inorder(root):
    if lc[root] != 0: inorder(lc[root])
    print(chr(root + ord('A') - 1), end='') 
    if rc[root] != 0: inorder(rc[root])

def postorder(root):
    if lc[root] != 0: postorder(lc[root])
    if rc[root] != 0: postorder(rc[root])
    print(chr(root + ord('A') - 1), end='') 
preorder(1)
print()
inorder(1)
print()
postorder(1)