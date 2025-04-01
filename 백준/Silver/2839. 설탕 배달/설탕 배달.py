n = int(input())
s = []


for x in range((n//5) + 1) :
    if (n - 5*x) % 3 == 0 :
        a = x
        b = (n - 5*x) / 3
        s.append(a+b)

if len(s) == 0:
    print(-1)

else :
    m = s[0]
    for num in s[1:] :
        if m > num :
            m = num

    print(int(m))