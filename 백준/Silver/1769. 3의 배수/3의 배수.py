import sys
import copy
import heapq
from collections import deque
from math import inf

sys.setrecursionlimit(100000)

input = sys.stdin.readline

n = int(input())
cnt = 0
running = True
if n < 10:
    if n in [3, 6, 9]:
        print(0)
        print("YES")
    else:
        print(0)
        print("NO")
    running = False
while running:
    L = list(map(int, list(str(n))))
    temp_num = sum(L)
    cnt += 1
    if temp_num < 10:
        print(cnt)
        if temp_num % 3 == 0:
            print("YES")
        else:
            print("NO")
        break
    n = temp_num
