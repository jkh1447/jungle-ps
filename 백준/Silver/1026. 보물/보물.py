import sys

n = int(sys.stdin.readline())

A = list(map(int, sys.stdin.readline().split()))
B = list(map(int, sys.stdin.readline().split()))

ans = 0

A.sort()

for i in range(n):
    ans += A[i] * max(B)
    B.pop(B.index(max(B)))

print(ans)