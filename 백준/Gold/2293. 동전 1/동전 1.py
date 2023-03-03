import sys
import copy
import heapq
from collections import deque
from math import inf

# sys.setrecursionlimit(100000)

input = sys.stdin.readline

n, k = map(int, input().split())
coins = []
for _ in range(n):
    coins.append(int(input()))

dp = [0 for _ in range(k + 1)]

dp[0] = 1

for i in range(n):
    coin = coins[i]
    for j in range(coin, k + 1):
        if (dp[j - coin] > 0):
            dp[j] += dp[j - coin]

print(dp[k])
