import sys
import copy
import heapq
from collections import deque
from math import inf

# sys.setrecursionlimit(100000)

input = sys.stdin.readline

n, k = map(int,input().split())
L = []
for i in range(n):
    L.append(list(map(int,input().split())))
L.sort(key=lambda x:(-x[1],-x[2],-x[3]))


cnt = 1
for i in range(n):
    if(L[i][0] == k):
        print(cnt)
    if(i == n -1): break

    if(L[i][1:] == L[i+1][1:]):
        continue
    else:
        cnt+=1