N = int(input())
A = list(map(int,input().split()))
order_A = [[i, A[i]] for i in range(N)]

order_A.sort(key=lambda x:x[1])

idx_order_A = [[i]+order_A[i] for i in range(N)]

idx_order_A.sort(key=lambda x:x[1])

for i in range(N):
    print(idx_order_A[i][0], end=" ")
print()