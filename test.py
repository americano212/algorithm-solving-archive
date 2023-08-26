from collections import deque
INF = float('inf')
v, e = map(int, input().split())

graph = [[] for _ in range(v+1)]

for _ in range(e):
    a, b, c = map(int, input().split())
    graph[a].append([b, c])

queue = deque()

result = INF
for start_node in range(1, v+1):
    queue.append([start_node, 0])
    distance = [INF] * (v+1)
    distance[start_node] = 0

    while (queue):
        now_node, now_cost = queue.popleft()
        # if (now_cost > distance[now_node]):
        #     continue
        for next_node, next_cost in graph[now_node]:
            if (next_node == start_node):
                result = min(result, now_cost+next_cost)
                print("??", start_node, result, now_cost, next_cost, now_node)
            if (distance[next_node] > now_cost+next_cost):
                distance[next_node] = now_cost+next_cost
                queue.append([next_node, next_cost])
print(result)
