import sys
sys.setrecursionlimit(100000)

n = int(input())
s = []
lst = []

for _ in range(n):
    x, r = map(int, sys.stdin.readline().strip().split())
    lst.append([x - r, 'L', r])  
    lst.append([x + r, 'R', r])  


lst.sort(key=lambda x: (x[0], -ord(x[1]), -x[2] if x[1] == 'L' else x[2]))

ans = 1  

for pos, state, r in lst:
    if state == 'L':  
        s.append([pos, r])
    else:  
        internal_length = 0  


        while s and s[-1][0] == 'C':
            internal_length += s.pop()[1] * 2


        if internal_length == 2 * r:
            ans += 2
        else:
            ans += 1

 
        s.pop()


        if s:
            s.append(['C', r])

print(ans)