import sys
import copy
from collections import deque

input = sys.stdin.readline
ans = 0
cnt = 0


def find(x):
    if (parent[x] != x):
        return find(parent[x])
    return x


def union(a, b):
    a = find(a)
    b = find(b)
    if (a < b):
        parent[b] = a
    else:
        parent[a] = b


n, m, k = map(int, input().split())

parent = [i for i in range(n + 1)]

edges = []

for i in range(m):
    a, b = map(int, input().split())
    edges.append([i + 1, a, b])
edges.sort()

for i in range(k):
    result = 0
    visited = []
    parent = [i for i in range(n + 1)]
    for edge in edges:
        cost, a, b = edge
        if (find(a) != find(b)):
            union(a, b)
            result += cost
            visited.append(edge)

    if (len(visited) == n - 1):
        print(result, end=" ")
    else:
        print(0, end=" ")
    edges = edges[1:]
print()
