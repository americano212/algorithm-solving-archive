import sys
import copy
import heapq
from collections import deque
from math import inf

# sys.setrecursionlimit(100000)

input = sys.stdin.readline

dx = [-1, 0, 1, 0, -1, -1, 1, 1]
dy = [0, 1, 0, -1, 1, -1, 1, -1]

n = int(input())

for i in range(n):
    print('*' * (i + 1))
for i in range(1, n):
    print('*' * (n - i))
