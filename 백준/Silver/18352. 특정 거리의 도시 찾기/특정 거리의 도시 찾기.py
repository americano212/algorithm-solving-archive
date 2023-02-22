import sys
import copy
import heapq
from collections import deque
from math import inf

# sys.setrecursionlimit(100000)

input = sys.stdin.readline

n, m, k, x = map(int, input().split())

L = [[] for _ in range(n + 1)]
distance = [inf for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    L[a].append([b, 1])

q = []
heapq.heappush(q, [0,x])
distance[x] = 0
while q:
    now_dist, now_node = heapq.heappop(q)
    if(distance[now_node] < now_dist):
        continue
    for i in L[now_node]:
        cost = now_dist + i[1]
        if cost < distance[i[0]]:
            distance[i[0]] = cost
            heapq.heappush(q, [cost,i[0]])

ans = []
for i in range(1,n+1):
    if(distance[i]==k):
        ans.append(i)

if(len(ans)==0):
    print(-1)
else:
    for i in ans:
        print(i)