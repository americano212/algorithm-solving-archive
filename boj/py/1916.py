from collections import deque
import sys
import heapq
INF = sys.maxsize

input = sys.stdin.readline

n = int(input())
m = int(input())

v = [[] for _ in range(n+1)]


for _ in range(m):
    start, end, cost = map(int, input().split())
    v[start].append([end, cost])
start_node, end_node = map(int, input().split())

distance = [INF] * (n+1)
way = [0 for _ in range(n+1)]

queue = [[start_node, 0]]

way[start_node] = start_node

while (queue):
    now_node, now_cost = heapq.heappop(queue)
    if (distance[now_node] < now_cost):
        continue
    for new_node, new_cost in v[now_node]:
        if (distance[new_node] > new_cost + now_cost):
            distance[new_node] = new_cost + now_cost
            way[new_node] = now_node
            heapq.heappush(queue, [new_node, new_cost + now_cost])
print(distance[end_node])
