t = int(input())
a = [[0 for j in range(15)] for i in range(15)] # 총 15개의 층, 14개의 호수, 1번째부터 하기위해 15

for i in range(1, 15):
    a[0][i] = i

def solve(k, n): # k층 n호의 인원을 구하자
    sum = 0
    for i in range(1, n+1):
        if a[k-1][i] != 0:
            sum += a[k-1][i]
        else:
            solve(k-1, i)
            sum += a[k-1][i]
    a[k][n] = sum

for _ in range(t):
    k = int(input()) #층
    n = int(input()) #호
    solve(k, n)
    print(a[k][n])