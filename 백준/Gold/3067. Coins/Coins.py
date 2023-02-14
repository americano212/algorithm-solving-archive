import sys
import copy
from collections import deque

input = sys.stdin.readline
ans = 0
cnt = 0

t = int(input())
for _ in range(t):
    n = int(input())
    coins = [0] + list(map(int,input().split()))
    m = int(input())

    dp = [[0]*(m+1) for _ in range(n+1)]
    for i in range(n+1):
        dp[i][0] = 1
    for i in range(1, n+1):
        for won in range(1, m+1):
            coin = coins[i]
            if(won < coin):
                dp[i][won] = dp[i-1][won]
            else:
                dp[i][won] = dp[i-1][won]  + dp[i][won-coin]
    print(dp[n][m])