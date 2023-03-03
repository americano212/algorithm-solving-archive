import sys
import copy
import heapq
from collections import deque
from math import inf

# sys.setrecursionlimit(100000)

input = sys.stdin.readline

n, m = map(int, input().split())
L = []
for _ in range(n):
    L.append(list(map(int, input()[:-1])))
visited = [[False] * m for _ in range(n)]

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]


def bfs():
    queue = deque([[0, 0]])
    while (queue):
        x,y = queue.popleft()
        for i in range(4):
            nx = dx[i] + x;
            ny = dy[i] + y;
            if (0 <= nx < n and 0 <= ny < m):
                if(visited[nx][ny] == False and L[nx][ny] != 0):
                    queue.append([nx, ny])
                    visited[nx][ny] = True
                    L[nx][ny] = L[x][y] + 1



bfs()

print(L[-1][-1])