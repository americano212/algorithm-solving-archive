import sys
import copy
import heapq
from collections import deque
from math import inf

# sys.setrecursionlimit(100000)

input = sys.stdin.readline

n = int(input())
L = [n-i for i in range(n)]
flag = 1
while(True):
    if(len(L)==0):
        break
    if(flag):
        print(L.pop(),end=" ")
    else:
        temp = L.pop()
        L = [temp] + L
    flag = 1 - flag


