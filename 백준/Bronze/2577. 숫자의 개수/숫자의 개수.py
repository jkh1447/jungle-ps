a = int(input())
b = int(input())
c = int(input())

d = a * b * c
lst = [0 for x in range(0, 10)]

while d != 0:
    tmp = d % 10
    lst[tmp] += 1
    d = d // 10

for i in range(10):
    print(lst[i])