import sys
from collections import deque

input = sys.stdin.readline

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

n = int(input())
L = list(map(int, input().split()))

ans = 0
visited =[False for _ in range(n)]

def dfs(cnt, arr):
    global ans
    if(cnt == n):
        temp = 0
        for i in range(1,n):
            temp += abs(arr[i]- arr[i-1])
        if (temp > ans):
            ans = temp
        return
    for i in range(n):
        if (visited[i]):
            continue
        visited[i] = True
        arr.append(L[i])
        dfs(cnt+1, arr)
        visited[i] = False
        arr.pop()
dfs(0,[])
print(ans)

