import sys

n = int(input())

coins = [2, 5]
flag = False
d = [0 for _ in range(n+1)]
if n < 5:
    if n % 2 == 0:
        print(n//2)
    else:
        print(-1)
else:


    tmp = n // 5
    for i in range(tmp, -1, -1):

        if (n - (5 * i)) % 2 == 0:
            print(i + ((n - (5 * i)) // 2))
            flag = True
            break

    if not flag:
        print(-1)