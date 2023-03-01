import sys
import copy
import heapq
from collections import deque
from math import inf

# sys.setrecursionlimit(100000)

input = sys.stdin.readline

a, b = map(int, input().split())
L = input().split()

L.sort()


def cnt_aeiou(s):
    cnt = 0
    for i in range(len(s)):
        if (s[i] in ['a', 'e', 'i', 'o', 'u']):
            cnt += 1
    return cnt


def dfs(word, idx):
    if (len(word) == a):
        if (0 < cnt_aeiou(word) < a - 1):
            print(''.join(word))
        return
    for i in range(idx, b):
        word.append(L[i])
        dfs(word, i + 1)
        word.pop()


dfs([], 0)
