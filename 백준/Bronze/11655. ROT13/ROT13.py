import sys
import copy
import heapq
from collections import deque
from math import inf

# sys.setrecursionlimit(100000)

input = sys.stdin.readline


s = input()
ans = []
lower = [a for a in range(ord('a'),ord('z')+1)]


upper = [a for a in range(ord('A'),ord('Z')+1)]


for i in range(len(s)):
    if('a' <= s[i] <= 'z'):
        ans.append(chr(lower[ord(s[i]) - ord('a') - 13]))
    elif('A' <= s[i] <= 'Z'):
        ans.append(chr(upper[ord(s[i]) - ord('A') - 13]))
    else:
        ans.append(s[i])
print(''.join(ans))