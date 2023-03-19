import sys
import copy
import heapq
from collections import deque
from math import inf

# sys.setrecursionlimit(100000)

input = sys.stdin.readline

dx = [-1, 0, 1, 0, -1, -1, 1, 1]
dy = [0, 1, 0, -1, 1, -1, 1, -1]

yut = ['D','C','B','A','E']

for i in range(3):
    L = list(map(int, input().split()))
    print(yut[sum(L)])
