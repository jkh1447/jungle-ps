import sys

n = int(sys.stdin.readline())

tr = []
dp = []
for i in range(1, 501):
    dp.append([0]*i)
for i in range(n):
    tr.append(list(map(int, sys.stdin.readline().split())))

dp[0][0] = tr[0][0]
if n != 1:
    dp[1][0] = dp[0][0] + tr[1][0]
    dp[1][1] = dp[0][0] + tr[1][1]
    for i in range(2, n):

        for j in range(0, i+1):
            if j == 0:
                dp[i][j] = dp[i-1][j] + tr[i][j]
            elif j == i:
                dp[i][j] = dp[i-1][j-1] + tr[i][j]
            else:
                dp[i][j] = tr[i][j] + max(dp[i-1][j-1], dp[i-1][j])

print(max(dp[n-1]))