import math

n, r, c = list(map(int, input().split()))

def func(n, r, c):
    # 함수의 정의 : 2^n 크기의 배열에서 r, c 의 방문순서
    if n == 1:
        if r == 0 and c == 0:
            return 0
        elif r == 0 and c == 1:
            return 1
        elif r == 1 and c == 0:
            return 2
        else:
            return 3
        
    if r < 2**(n-1) and c < 2**(n-1):
        #1사분면 
        return func(n-1, r, c)
    elif r < 2**(n-1) and c >= 2**(n-1):
        #2사분면
        return 1 * 2**(n-1) * 2**(n-1) + func(n-1, r, c-2**n / 2)
    elif r >= 2**(n-1) and c < 2**(n-1):
        #3사분면
        return 2 * 2**(n-1) * 2**(n-1) + func(n-1, r-2**n / 2, c)
    else:
        return 3 * 2**(n-1) * 2**(n-1) + func(n-1, r-2**n / 2, c-2**n / 2)
    
print(func(n, r, c))
