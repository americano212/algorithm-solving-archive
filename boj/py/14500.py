import sys
input=sys.stdin.readline

n, m  = map(int, input().split())

L = []
for _ in range(n):
    L.append(list(map(int, input().split())))

maximum = 0

dx = [-1,0,1,0]
dy = [0,1,0,-1]

visit = [[False] * m for _ in range(n)]


def dfs(result, count, x, y):
    global maximum
    if(count == 4):
        maximum = max(maximum, result)
        return
        
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if(0<=nx<n and 0<=ny<m):
            if(visit[nx][ny] == False):
                visit[nx][ny] = True
                dfs(result + L[nx][ny], count+1, nx, ny)
                visit[nx][ny] = False
    


def solve_etc(start):
    global maximum
    x, y = start
    for a in range(4):
        temp = L[x][y]
        for b in range(3):
            t = (a+b)%4
            nx = x + dx[t]
            ny = y + dy[t]
            if not (0<=nx<n and 0<=ny<m):
                temp = 0
                break
            temp += L[nx][ny]
        maximum = max(maximum, temp)

for i in range(n):
    for j in range(m):
        start = [i,j]

        visit[i][j] = True
        dfs(L[i][j], 1, i, j)
        visit[i][j] = False

        solve_etc(start)


print(maximum)