N, K = map(int, input().split())

min = (K*(K+1))/2

p = min % K

if N < min :
    print(-1)

else :
    if N % K == p :
        print(K-1)
    else :
        print(K)
