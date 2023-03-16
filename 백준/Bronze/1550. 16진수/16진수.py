import sys
import copy
import heapq
from collections import deque
from math import inf
from itertools import permutations

# sys.setrecursionlimit(100000)

# def find_set(x):
#     while x != parent[x]:
#         x = parent[x]
#     return x

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

input = sys.stdin.readline

print(int(input(), 16))