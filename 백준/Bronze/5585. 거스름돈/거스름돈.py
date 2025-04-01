price = int(input())

change = [500, 100, 50, 10, 5, 1]

c = 1000 - price
count = 0
i = 0
for i in range(6) :
    count += c//change[i]
    c = c%change[i]


print(count)