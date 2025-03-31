r, c = list(map(int, input().split()))
ans = 0
room = []
trash = [0] * 1

for i in range(r):
	room.append(list(map(int, input().split())))

for i in range(r):
	for j in range(c):
		if room[i][j] == 1:
			trash[0] += 1

x = y = 0

while trash[0] != 0:

	while True:

		if room[x][y] == 1:
			room[x][y] = 0
			trash[0] -= 1
		cnt = 0
		for i in range(y, c):
			if room[x][i] == 1:
				cnt += 1

		if cnt > 0:
			y += 1
		else:
			if x == r-1:
				break
			else:
				x += 1

	x = y = 0
	ans += 1


print(ans)