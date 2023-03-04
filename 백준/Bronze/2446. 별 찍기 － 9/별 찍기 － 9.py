import sys
import copy
import heapq
from collections import deque
from math import inf

# sys.setrecursionlimit(100000)

input = sys.stdin.readline

n = int(input())
for i in range(n):
    print(" " * i, end="")
    print("*" * (2 * (n - i) - 1))
for i in range(2, n + 1):
    print(" " * (n - i), end="")
    print("*" * (2 * i - 1))
