import sys
import copy
import heapq
from collections import deque
from math import inf

# sys.setrecursionlimit(100000)

input = sys.stdin.readline

dx = [-1, 0, 1, 0, -1, -1, 1, 1]
dy = [0, 1, 0, -1, 1, -1, 1, -1]

max_ = 0
n = 0
for i in range(4):
    a, b = map(int, input().split())
    n += (b - a)
    max_ = max(max_, n)
print(max_)
