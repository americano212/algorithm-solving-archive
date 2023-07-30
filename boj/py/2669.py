L = [[0]*101 for _ in range(101)]

for _ in range(4):
    a, b, c, d = map(int, input().split())
    for i in range(a, c):
        for j in range(b, d):
            L[i][j] = 1
ans = 0
for i in range(101):
    ans += sum(L[i])

print(ans)
