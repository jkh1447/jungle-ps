max = int(input())
index = 1
for i in range(2, 10):
    n = int(input())
    if n > max:
        max = n
        index = i
print(max)
print(index)