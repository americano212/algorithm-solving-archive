import sys
import copy
import heapq
from collections import deque
from math import inf

# sys.setrecursionlimit(100000)

input = sys.stdin.readline


L = list(map(int, input().split()))

L.sort()
print(L[1])