form = input()

sum = form.split("-")
result = 0

for i in sum[0].split("+"):
    result += int(i)

for i in sum[1:]:
    for j in i.split("+"):
        result -= int(j)


print(result)