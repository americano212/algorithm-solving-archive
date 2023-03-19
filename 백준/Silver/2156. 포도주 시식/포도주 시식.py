import sys
import copy
import heapq
from collections import deque
from math import inf

# sys.setrecursionlimit(100000)

input = sys.stdin.readline

dx = [-1, 0, 1, 0, -1, -1, 1, 1]
dy = [0, 1, 0, -1, 1, -1, 1, -1]

n = int(input())
L = []
for i in range(n):
    L.append(int(input()))

dp = [[0, 0, 0] for _ in range(n)]
dp[0][1] = L[0]  # 2연속, 1연속, 0연속
for i in range(1, n):
    dp[i][2] = dp[i - 1][1] + L[i]
    dp[i][1] = dp[i - 1][0] + L[i]
    dp[i][0] = max(dp[i - 1])
print(max(dp[-1]))
