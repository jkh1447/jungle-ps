n, k = list(map(int, input().split()))

s = list(map(int, input().split()))
f = []
count = 0
for i in range(k):
    if s[i] in f:
        continue
    if len(f) < n:
        f.append(s[i])
    else:
        idx = -1
        val = 0
        count +=1
        tmp = s[i:]
        for x in f:
            if x in tmp:
                target = tmp.index(x)
                if idx < target:
                    idx = target
                    val = x
            else:
                val = x
                break
        f[f.index(val)] = s[i]




print(count)