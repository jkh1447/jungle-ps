n, m = list(map(int, input().split())) # 책의 개수, 들 수 있는 책 수
c = list(map(int, input().split()))

pc = []
nc = []
ans = 0
for i in range(n):
    if c[i] > 0:
        pc.append(c[i])
    else:
        nc.append(c[i])

    pc.sort(reverse=True)
    nc.sort()

i = 0
if pc:
    while i < len(pc):
        ans += pc[i] * 2

        i += m

    i = 0
if nc:
    while i < len(nc):
        ans += abs(nc[i]) * 2
        i += m
if pc and nc:
    if pc[0] > abs(nc[0]):
        ans -= pc[0]
    else :
        ans -= abs(nc[0])
else:
    if pc:
        ans -= pc[0]
    else:
        ans -= abs(nc[0])
print(ans)