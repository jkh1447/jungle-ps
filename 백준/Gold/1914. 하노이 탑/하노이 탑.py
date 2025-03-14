import math

# a에서 c로 n개를 옮기는 함수
# n이 1일땐 그냥 옮기기

def func(a, c, n):
    if n == 1:
        print(f"{a} {c}")
        return

    func(a, 6-a-c, n-1)
    print(f"{a} {c}")
    func(6-a-c, c, n-1)


n = int(input())
if n > 20:
    print(2**n - 1)
else:    
    print(2**n - 1)
    func(1, 3, n)