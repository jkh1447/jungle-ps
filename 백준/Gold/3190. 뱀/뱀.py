board = int(input())  # 보드 크기
deque = [[1, 1]]  # 뱀의 위치 (초기: (1,1))
apple_num = int(input())  # 사과 개수
apple = [list(map(int, input().split())) for _ in range(apple_num)]  # 사과 위치
result = 0
exit_flag = False

L = int(input())  # 방향 전환 횟수
commands = [input().split() for _ in range(L)]  # (시간, 방향)

# 동(→), 남(↓), 서(←), 북(↑) 순서
directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
dir_idx = 0  # 초기 방향: 동쪽
now_place = [1, 1]
commands.append([101, 'O'])
for n, c in commands:
    n = int(n)
    # print(f"n, c: {n}, {c}")
    while result < n:
        # print(f"dir_idx: {dir_idx}")
        # 이동
        now_place[0] += directions[dir_idx][0]
        now_place[1] += directions[dir_idx][1]
        deque.append(now_place[:])
   
        # 충돌 검사
        if not (1 <= now_place[0] <= board and 1 <= now_place[1] <= board):
            result += 1
            exit_flag = True
            break
        if now_place in deque[:-1]:  # 머리가 몸에 닿았는지 확인
            result += 1
            exit_flag = True
            break

        # 사과가 없으면 꼬리 제거
        if now_place not in apple:
            deque.pop(0)
        else:
            apple.remove(now_place)  # 사과 먹으면 리스트에서 제거
        result += 1
        if now_place in deque[:-1]:  # 머리가 몸에 닿았는지 확인
            result += 1
            exit_flag = True
            break
        # print(f"time: {result}")
        # print(f"snake: {deque}")
        
    if exit_flag:
        break
    
    # 방향 전환
    if c == 'D':  # 오른쪽 회전
        dir_idx = (dir_idx + 1) % 4
    else:  # 'L' (왼쪽 회전)
        dir_idx = (dir_idx - 1) % 4

print(result)  # 초기 1초 포함