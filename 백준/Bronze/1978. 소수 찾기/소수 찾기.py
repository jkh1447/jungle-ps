import math
def isPrime(n):
    if n == 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n%i==0: 
            return False
    return True
n = int(input())
lst = list(map(int, input().split()))
count = 0
for i in lst:
    if isPrime(i): 
        count+=1
print(count)
        