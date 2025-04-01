a = [0] * 100

def solve(n):
    if n == 0:
        return 0
    if n == 1:
        return 1

    if a[n] != 0:
        return a[n]
    else:
        a[n] = solve(n-1) + solve(n-2)
        return a[n]

n = int(input())
print(solve(n))