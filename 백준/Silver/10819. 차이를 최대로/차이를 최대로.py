import math
import sys

def permutation(nums, k):
    def func(path, used):
        if len(path) == k:
            result.append(path[:])
            return
        for i in range(len(nums)):
            if not used[i]:
                used[i] = True
                path.append(nums[i])
                func(path, used)
                used[i] = False
                path.pop()

    result = []
    func([], [False] * len(nums))
    return result

n = int(input())
lst = list(map(int, sys.stdin.readline().split()))

max = 0
for arr in permutation(lst, len(lst)):
    sum = 0
    for i in range(len(arr) - 1):
        sum += abs(arr[i] - arr[i+1])
    if max < sum:
        max = sum

print(max)
