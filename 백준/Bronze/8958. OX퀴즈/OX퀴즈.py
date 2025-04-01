t = int(input())



for i in range(t):
    ans = 0
    ox = input()
    cur = 0
    for i in ox:
        if i == 'O':
            cur += 1
            ans += cur
        else:
            cur = 0
    print(ans)
    ans = 0