n = int(input())
k = int(input())
s = list(map(int, input().split()))

ans = 0
dist = []
s.sort()
for i in range(n-1, 0, -1):
    dist.append(abs(s[i]-s[i-1]))

dist.sort(reverse=True)

for i in range(k-1, len(dist)):
    ans += dist[i]

print(ans)