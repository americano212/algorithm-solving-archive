c = int(input())
n = int(input())

L = [[0]*(c+1) for _ in range(c+1)]
visited = [0 for _ in range(c+1)]
for _ in range(n):
    a,b = map(int,input().split())
    L[a][b] = 1
    L[b][a] = 1


def dfs(start):
    visited[start] = 1
    for i in range(1, c+1):
        if(L[start][i] == 1 and visited[i] == 0):
            dfs(i)
    

dfs(1)
print(sum(visited) - 1)