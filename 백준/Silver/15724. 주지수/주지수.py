import sys
import copy
from collections import deque
from math import inf

# sys.setrecursionlimit(100000)

input = sys.stdin.readline

n, m = map(int, input().split())
L = [[0] * (m + 1)]
for _ in range(n):
    L.append([0] + list(map(int, input().split())))

for i in range(1, m + 1):
    for j in range(1, n + 1):
        L[j][i] = L[j - 1][i] + L[j][i - 1] + L[j][i] - L[j - 1][i - 1]


t = int(input())

for _ in range(t):
    x1, y1, x2, y2 = map(int, input().split())
    print(L[x2][y2] + L[x1 - 1][y1 - 1] - L[x2][y1 - 1] - L[x1 - 1][y2])
