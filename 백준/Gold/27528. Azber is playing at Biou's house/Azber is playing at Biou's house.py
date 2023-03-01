import sys
import copy
import heapq
from collections import deque
from math import inf

# sys.setrecursionlimit(100000)

input = sys.stdin.readline

n = int(input())
L = [0] + list(map(int, input().split()))

dp = [[0, 0] for _ in range(3000)]
dp[1] = [L[1], L[1]]
dp_l = [[0, 0] for _ in range(3000)]
dp_l[1] = [L[1], L[1]]
dp_r = [[0, 0] for _ in range(3000)]
dp_r[1] = [L[1], L[1]]

for i in range(1, n):
    for j in range(2 ** i, 2 ** (i + 1)):

        temp_l = [0, 0]
        if (j == 2 ** i):
            temp_l[0] = min(dp[j // 2][1], 0) + L[j]
            temp_l[1] = max(dp[j // 2][0], 0) + L[j]
        else:
            temp_l[0] = min(dp_l[j - 1][1], dp[j // 2][1], 0) + L[j]
            temp_l[1] = max(dp_l[j - 1][0], dp[j // 2][0], 0) + L[j]
        dp_l[j] = temp_l

        temp_r = [0, 0]
        right_j = 2 ** (i + 1) + 2 ** i - 1 - j
        if (right_j == 2 ** (i + 1) - 1):
            temp_r[0] = min(dp[right_j // 2][1], 0) + L[right_j]
            temp_r[1] = max(dp[right_j // 2][0], 0) + L[right_j]
        else:
            temp_r[0] = min(dp_r[right_j + 1][1], dp[right_j // 2][1], 0) + L[right_j]
            temp_r[1] = max(dp_r[right_j + 1][0], dp[right_j // 2][0], 0) + L[right_j]
        dp_r[right_j] = temp_r

    for j in range(2 ** i, 2 ** (i + 1)):
        temp_dp = [0, 0]
        temp_dp[0] = min(dp_l[j][0], dp_r[j][0])
        temp_dp[1] = max(dp_l[j][1], dp_r[j][1])
        dp[j] = temp_dp
# print("dp_l",dp_l)
# print("dp_r",dp_r)
for i in range(1, 2 ** n):
    print(dp[i][0], end=' ')
