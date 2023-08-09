from collections import deque
import sys
INF = sys.maxsize

n, e = map(int, input().split())

v = [[] for _ in range(n+1)]

for _ in range(e):
    a, b, c = map(int, input().split())
    v[a].append([b, c])
    v[b].append([a, c])
v1, v2 = map(int, input().split())

final_result = INF


def dijkstra(target):
    temp_result = 0
    for start, end in target:
        queue = deque()
        queue.append([start, 0])
        distance = [INF] * (n+1)
        distance[start] = 0
        while (queue):
            now_node, now_cost = queue.popleft()
            if (distance[now_node] < now_cost):
                continue
            for new_node, new_cost in v[now_node]:
                if (distance[new_node] > new_cost + now_cost):
                    distance[new_node] = new_cost + now_cost
                    queue.append([new_node, new_cost + now_cost])
        temp_result += distance[end]
    return temp_result


target = [[1, v1], [v1, v2], [v2, n]]

result = dijkstra(target)
final_result = min(final_result, result)

target = [[1, v2], [v2, v1], [v1, n]]

result = dijkstra(target)
final_result = min(final_result, result)

if (final_result == INF):
    print(-1)
else:
    print(final_result)
