n = int(input())
L = list(map(int, input().split()))
# print(L)
dp = [0 for _ in range(n)]
dp_rev = [0 for _ in range(n)]
dp[0] = 1
for i in range(1,n):
    maximum = 0
    for j in range(i):
        if(L[i] > L[j]):
            maximum = max(maximum, dp[j])
    dp[i] = maximum + 1
# print(dp)
L.reverse()
dp_rev[0] = 1
for i in range(1,n):
    maximum = 0
    for j in range(i):
        if(L[i] > L[j]):
            maximum = max(maximum, dp_rev[j])
    dp_rev[i] = maximum + 1
dp_rev.reverse()
# print(dp_rev)
result = 0
for i in range(n):
    result = max(result, dp[i] + dp_rev[i] - 1)
print(result)