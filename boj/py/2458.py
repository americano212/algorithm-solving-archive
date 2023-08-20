INF = float('inf')
n, m = map(int, input().split())
graph = [[INF]*(n+1) for _ in range(n+1)]

for _ in range(m):
    src, dst = map(int, input().split())
    graph[src][dst] = 1

for k in range(1, n+1):
    graph[k][k] = 1
    for i in range(1, n+1):
        for j in range(1, n+1):
            graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j])

result = 0
for i in range(1, n+1):
    flag = 1
    for j in range(1, n+1):
        if (graph[i][j] == INF and graph[j][i] == INF):
            flag = 0
    if flag:
        result += 1
print(result)
