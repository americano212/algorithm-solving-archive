import sys
import copy
import heapq
from collections import deque
from math import inf
from itertools import permutations

# sys.setrecursionlimit(100000)

def find_set(x):
    while x != parent[x]:
        x = parent[x]
    return x

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

input = sys.stdin.readline

v, e = map(int, input().split())
L = []
for i in range(e):
    L.append(list(map(int, input().split())))
L.sort(key=lambda x: x[2])


parent = [i for i in range(v + 1)]

ans = 0

for i in range(e):
    a = L[i][0]
    b = L[i][1]
    c = L[i][2]
    if(find_set(a) != find_set(b)):
        parent[find_set(b)] = find_set(a)
        ans += c

print(ans)
