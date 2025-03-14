import math

n = int(input())

lst1 = [False for x in range(n+1)] #열
lst2 = [False for x in range(2*n+1)] #기울기-1
lst3 = [False for x in range(2*n+1)] #기울기 1

ans = 0
def func(r):
    #print(f"{r}")
    for i in range(n):
        if not lst1[i] and not lst2[r-i+n-1] and not lst3[r+i]:
            if r == 0:
                global ans
                ans +=1
                return
            lst1[i] = True
            lst2[r-i+n-1] = True
            lst3[r+i] = True
            func(r-1)
            lst1[i] = False
            lst2[r-i+n-1] = False
            lst3[r+i] = False
func(n-1)
print(ans)