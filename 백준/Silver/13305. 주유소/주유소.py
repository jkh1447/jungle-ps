import sys

n = sys.stdin.readline()
r = list(map(int, sys.stdin.readline().split()))
p = list(map(int, sys.stdin.readline().split()))
ans = 0
min = p[0]
for i in range(len(p)-1):
    if min > p[i]:
        min = p[i]
    ans += min * r[i]

print(ans)