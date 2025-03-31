import sys

n = sys.stdin.readline()
sum = 0
n = n.strip()
if '0' not in n:
    print(-1)
else:
    for i in n:
        sum += int(i)

    if sum % 3 != 0:
        print(-1)
    else:
        n = ''.join(sorted(n, reverse=True))
        print(n)