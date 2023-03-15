import sys
import copy
import heapq
from collections import deque
from math import inf
from itertools import permutations

# sys.setrecursionlimit(100000)

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

input = sys.stdin.readline

n, s = map(int, input().split())
L = list(map(int, input().split()))
prefix_sum = [0]
for i in range(len(L)):
    prefix_sum.append(prefix_sum[-1] + L[i])



a = 0
b = 1
min_len = n + 1
while (True):
    if (a == n + 1): break
    diff = prefix_sum[b] - prefix_sum[a]


    if (diff >= s):
        min_len = min(min_len, b - a)

    if (diff >= s):
        if (a == b):
            b += 1
            if (b == n + 1): break
        else:
            a += 1
    else:
        if (b == n):
            a += 1
        else:
            b += 1

if (min_len == n + 1):
    print(0)
else:
    print(min_len)
