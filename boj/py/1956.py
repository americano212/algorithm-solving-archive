INF = float('inf')
n, m = map(int, input().split())
graph = [[INF]*(n+1) for _ in range(n+1)]

for _ in range(m):
    src, dst, cost = map(int, input().split())
    graph[src][dst] = cost

for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j])

# for items in graph:
#     print(*items)
result = INF
for i in range(1, n):
    result = min(result, graph[i][i])
if (result == INF):
    print(-1)
else:
    print(result)
