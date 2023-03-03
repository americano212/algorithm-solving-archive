import sys
import copy
import heapq
from collections import deque
from math import inf

# sys.setrecursionlimit(100000)

input = sys.stdin.readline

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

s = input()[:-1]
L = []
for i in range(len(s)):
    if(i%10 == 0):
        L.append("\n")
    L.append(s[i])
print(''.join(L[1:]))