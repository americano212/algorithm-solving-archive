t = int(input())
for _ in range(t):
    n = int(input())
    L = []
    for i in range(2):
        L.append(list(map(int,input().split())))

    if(n == 1):
        print(max(L[0][0], L[1][0]))
        continue
    L[0][1] += L[1][0]
    L[1][1] += L[0][0]
    for i in range(2, n):
        L[0][i] += max(L[1][i-1], L[1][i-2])
        L[1][i] += max(L[0][i-1], L[0][i-2])
    
    print(max(L[0][n-1], L[1][n-1]))