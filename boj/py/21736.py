from collections import deque
# https://www.acmicpc.net/problem/21736
n,m = map(int,input().split())
L = []
for _ in range(n):
    L.append(list(input()))


queue = deque()



for i in range(n):
    for j in range(m):
        if(L[i][j]== 'I'):
            queue.append([i, j])

dx = [-1,0,1,0]
dy = [0,1,0,-1]

cnt = 0
def bfs():
    global cnt
    x, y = queue.popleft()
    
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if(0<=nx<n and 0<=ny<m):
            if(L[nx][ny] != 'X'):
                if(L[nx][ny] == 'P'):
                    cnt += 1
                L[nx][ny] = 'X'
                queue.append([nx, ny])


while(len(queue) > 0):
    bfs()


if(cnt == 0):
    print("TT")
else:
    print(cnt)