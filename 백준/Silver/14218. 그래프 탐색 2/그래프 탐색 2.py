import sys
from collections import deque

input = sys.stdin.readline

n, m = map(int, input().split())
INF = 1001
L = [[0] * (n + 1) for _ in range(n + 1)]
distance = [INF for _ in range(n + 1)]
distance[1] = 0

for _ in range(m):
    a, b = map(int, input().split())
    L[a][b] = 1
    L[b][a] = 1
t = int(input())


def bfs(target):
    visited = [False for _ in range(n + 1)]
    queue = deque()
    queue.append(target)
    while (queue):
        node, path = queue.popleft()
        if (distance[node] > path):
            distance[node] = path
        visited[node] = True
        for i in range(len(L[node])):
            if (L[node][i] == 1 and visited[i] == False):
                queue.append([i, path + 1])
                visited[i] = True


for _ in range(t):
    a, b = map(int, input().split())
    L[a][b] = 1
    L[b][a] = 1
    bfs([1, 0])
    for i in range(1, n + 1):
        if (distance[i] == INF):
            print(-1, end=" ")
        else:
            print(distance[i], end=" ")
    print()
