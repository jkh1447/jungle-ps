n, c = list(map(int, input().split()))

m = int(input())

ans = 0
info = []
b = 0

for i in range(m):
    info.append(list(map(int, input().split())))

info.sort(key=lambda x : x[1])

r = [c] * (n-1)

for i in range(m):
    min = c
    for j in range(info[i][0]-1, info[i][1]-1): #최솟값 구하기
        if min > r[j]:
            min = r[j]
    if min >= info[i][2]:
        for j in range(info[i][0]-1, info[i][1]-1):
            r[j] -= info[i][2]
        ans += info[i][2]
    else:
        for j in range(info[i][0]-1, info[i][1]-1):
            r[j] -= min
        ans += min



print(ans)
