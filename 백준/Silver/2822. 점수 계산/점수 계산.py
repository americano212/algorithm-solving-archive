import sys
import copy
from collections import deque
from math import inf

# sys.setrecursionlimit(100000)

input = sys.stdin.readline

L = []
for i in range(8):
    L.append([int(input()), i + 1])
L.sort()
number = []
result = 0
for i in range(3, 8):
    number.append(L[i][1])
    result += L[i][0]
print(result)
number.sort()
print(*number)
