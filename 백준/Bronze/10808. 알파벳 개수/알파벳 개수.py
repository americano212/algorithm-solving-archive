import sys
import copy
import heapq
from collections import deque
from math import inf

# sys.setrecursionlimit(100000)

input = sys.stdin.readline

s = input()[:-1]
ans = [0 for _ in range(26)]

for i in range(len(s)):
    ans[ord(s[i])-ord('a')]+=1
print(*ans)