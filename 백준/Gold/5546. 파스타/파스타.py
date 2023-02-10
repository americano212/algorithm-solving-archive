import sys

input = sys.stdin.readline

N, K = map(int, input().split())
dp = [[[0, 0, 0], [0, 0, 0]] for _ in range(N + 1)]
fix = [0 for _ in range(N + 1)]

for i in range(K):
    a, b = map(int, input().split())
    fix[a] = b

if (fix[1] == 1):
    dp[1][0] = [1, 0, 0]
elif (fix[1] == 2):
    dp[1][0] = [0, 1, 0]
elif (fix[1] == 3):
    dp[1][0] = [0, 0, 1]
else:
    dp[1][0] = [1, 1, 1]

for i in range(2, N + 1):
    if (fix[i] == 1):
        dp[i][0][0] = (dp[i - 1][0][1] + dp[i - 1][1][1] + dp[i - 1][0][2] + dp[i - 1][1][2]) % 10000
        dp[i][1][0] = dp[i - 1][0][0]
    elif (fix[i] == 2):
        dp[i][0][1] = (dp[i - 1][0][0] + dp[i - 1][1][0] + dp[i - 1][0][2] + dp[i - 1][1][2]) % 10000
        dp[i][1][1] = dp[i - 1][0][1]
    elif (fix[i] == 3):
        dp[i][0][2] = (dp[i - 1][0][0] + dp[i - 1][1][0] + dp[i - 1][0][1] + dp[i - 1][1][1]) % 10000
        dp[i][1][2] = dp[i - 1][0][2]
    else:
        dp[i][0][0] = (dp[i - 1][0][1] + dp[i - 1][1][1] + dp[i - 1][0][2] + dp[i - 1][1][2]) % 10000
        dp[i][1][0] = dp[i - 1][0][0]
        dp[i][0][1] = (dp[i - 1][0][0] + dp[i - 1][1][0] + dp[i - 1][0][2] + dp[i - 1][1][2]) % 10000
        dp[i][1][1] = dp[i - 1][0][1]
        dp[i][0][2] = (dp[i - 1][0][0] + dp[i - 1][1][0] + dp[i - 1][0][1] + dp[i - 1][1][1]) % 10000
        dp[i][1][2] = dp[i - 1][0][2]

print((sum(dp[N][0]) + sum(dp[N][1])) % 10000)
