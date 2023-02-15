import sys
import copy
from collections import deque
from math import inf

# sys.setrecursionlimit(100000)

input = sys.stdin.readline

n = int(input())
L = [0]
for i in range(n):
    L.append(L[-1] + int(input()))

result = 0

a = 1
b = 1
while (True):
    s1 = L[b] - L[a - 1]
    s2 = L[-1] - s1
    if (s1 < s2):
        b += 1
    else:
        a += 1
    result = max(result, min(s1, s2))
    if (b == n + 1): break
print(result)
