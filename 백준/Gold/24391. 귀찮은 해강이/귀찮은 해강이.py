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


n, m = map(int, input().split())

parent = [i for i in range(n + 1)]

for _ in range(m):
    a, b = map(int, input().split())
    union(a, b)

L = list(map(int,input().split()))
for i in range(1,len(L)):
    if(find(L[i]) != find(L[i-1])):
        ans += 1
print(ans)