import sys
import copy
from collections import deque
from math import inf, lcm

# sys.setrecursionlimit(100000)

input = sys.stdin.readline

n = int(input())
L = []
for i in range(n):
    L.append(list(input().split()))
    L[-1][1] = int(L[-1][1])
    L[-1][2] = int(L[-1][2])
    L[-1][3] = int(L[-1][3])
L.sort(key=lambda x: (x[3],x[2],x[1]))

print(L[-1][0])
print(L[0][0])