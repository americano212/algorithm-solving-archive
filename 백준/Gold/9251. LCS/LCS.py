import sys
import copy
import heapq
from collections import deque
from math import inf

# sys.setrecursionlimit(100000)

input = sys.stdin.readline

s1 = input()[:-1]
s2 = input()[:-1]
a = len(s1)
b = len(s2)
dp = [[0] * (a + 1) for _ in range(b + 1)]

for i in range(1, a + 1):
    for j in range(1, b + 1):
        if (s1[i - 1] == s2[j - 1]):
            dp[j][i] = dp[j - 1][i - 1] + 1
        else:
            dp[j][i] = max(dp[j - 1][i],dp[j][i - 1])


print(dp[-1][-1])
