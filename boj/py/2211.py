from collections import deque
import sys
INF = sys.maxsize

n, m = map(int, input().split())
v = [[] for _ in range(n+1)]
for _ in range(m):
    a, b, c = map(int, input().split())
    v[a].append([b, c])
    v[b].append([a, c])


distance = [INF for _ in range(n+1)]
distance[1] = 0

parent = [0 for _ in range(n+1)]

queue = deque()
queue.append([1, 0])

while (queue):
    now_node, now_cost = queue.popleft()
    if (distance[now_node] < now_cost):
        continue
    for new_node, new_cost in v[now_node]:
        if (distance[new_node] > new_cost + now_cost):
            distance[new_node] = new_cost + now_cost
            queue.append([new_node, new_cost + now_cost])

            parent[new_node] = now_node


print(n - 1)
for i in range(2, n + 1):
    print(parent[i], i)
