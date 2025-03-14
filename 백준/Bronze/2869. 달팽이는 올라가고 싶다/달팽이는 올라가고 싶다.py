a, b, v = list(map(int, input().split()))
count = 0
snail = 0

if (v-b) % (a-b) == 0:
    print((v-b) // (a-b))
else:
    print((v-b) // (a-b) + 1)
