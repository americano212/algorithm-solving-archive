import sys
from collections import deque

input = sys.stdin.readline

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

M, N = map(int, input().split())
L = [list(input().rstrip()) for _ in range(M)]
visited = [[False] * N for _ in range(M)]

def bfs(node):
    queue = deque()
    queue.append(node)
    while (queue):
        x, y = queue.popleft()
        visited[x][y] = True
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if (0 <= nx < M and 0 <= ny < N and L[nx][ny] == '0'):
                if (visited[nx][ny] == False):
                    queue.append([nx, ny])
                    visited[nx][ny] = True
    return


for i in range(N):
    if (L[0][i] == '1'): continue
    bfs([0,i])
if (sum(visited[-1])):
    print("YES")
else:
    print("NO")
