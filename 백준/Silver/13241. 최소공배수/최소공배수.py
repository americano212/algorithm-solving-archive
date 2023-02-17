import sys
import copy
from collections import deque
from math import inf, lcm

# sys.setrecursionlimit(100000)

input = sys.stdin.readline

n,m = map(int,input().split())
print(lcm(n,m))