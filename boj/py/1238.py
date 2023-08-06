from collections import deque
import sys
INF = sys.maxsize

n, m, x = map(int, input().split())
v = [[] for _ in range(n+1)]
for _ in range(m):
    a, b, t = map(int, input().split())
    v[a].append([b, t])

maximum = 0

for start_node in range(1, n+1):
    queue = deque()
    queue.append([start_node, 0])
    go_time = [INF] * (n+1)
    go_time[start_node] = 0
    while (queue):
        now_node, now_time = queue.popleft()
        for new_node, new_time in v[now_node]:
            if (go_time[new_node] > new_time + now_time):
                go_time[new_node] = new_time + now_time
                queue.append([new_node, new_time + now_time])

    come_time = [INF] * (n+1)
    come_time[x] = 0
    queue.append([x, 0])
    while (queue):
        now_node, now_time = queue.popleft()
        for new_node, new_time in v[now_node]:
            if (come_time[new_node] > new_time + now_time):
                come_time[new_node] = new_time + now_time
                queue.append([new_node, new_time + now_time])
    maximum = max(maximum, go_time[x] + come_time[start_node])
print(maximum)
