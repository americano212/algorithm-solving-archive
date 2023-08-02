from collections import deque
import sys
INF = sys.maxsize

n, m, r = map(int, input().split())
score = [0] + list(map(int, input().split()))
v = [[] for _ in range(n+1)]
for _ in range(r):
    a, b, l = map(int, input().split())
    v[a].append([b, l])
    v[b].append([a, l])

maximum = 0
for start_node in range(1, n+1):
    queue = deque()
    queue.append([start_node, 0])
    distance = [INF] * (n+1)
    distance[start_node] = 0
    while (queue):
        now_node, now_cost = queue.popleft()
        for new_node, new_cost in v[now_node]:
            if (distance[new_node] > new_cost + now_cost):
                distance[new_node] = new_cost + now_cost
                queue.append([new_node, new_cost + now_cost])
    temp_score = 0
    for i in range(1, len(distance)):
        if (distance[i] <= m):
            temp_score += score[i]
    maximum = max(maximum, temp_score)
print(maximum)
