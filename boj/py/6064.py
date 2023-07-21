# https://www.acmicpc.net/board/view/21503
import sys
input=sys.stdin.readline


t = int(input())
for _ in range(t):
    M,N,x,y = map(int,input().split())
    k = x
    flag = 1
    while (k <= M*N):
        if (k - x) % M == 0 and (k - y) % N == 0:
            print(k)
            flag = 0
            break
        k += M
    if(flag):
        print(-1)
