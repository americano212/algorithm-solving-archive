import sys
from collections import deque
import copy

input = sys.stdin.readline

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

n, m = map(int, input().split())
L = list(map(int, input().split()))

L.sort()
ans = []

visited = [False for _ in range(n)]


def dfs(start):
    if (len(ans) == m):
        print(*ans)
        return
    cnt = 0
    for i in range(start, n):
        if (visited[i]):
            continue
        if (cnt == L[i]):
            continue
        visited[i] = True
        cnt = L[i]
        ans.append(L[i])
        dfs(i + 1)
        visited[i] = False
        ans.pop()


dfs(0)
