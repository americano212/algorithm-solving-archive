import sys
import copy
from collections import deque
from math import inf

# sys.setrecursionlimit(100000)

input = sys.stdin.readline

n = int(input())
s1 = input()
s2 = input()

new_s1 = []
new_s2 = []

flag = True
for i in range(n):
    if (i == 0 or i == n - 1):
        if (s1[i] != s2[i]):
            flag = False
    else:
        if (s1[i] not in ['a', 'e', 'i', 'o', 'u']):
            new_s1.append(s1[i])

        if (s2[i] not in ['a', 'e', 'i', 'o', 'u']):
            new_s2.append(s2[i])

if (new_s2 != new_s1):
    flag = False

test_s1 = list(s1)
test_s2 = list(s2)
test_s1.sort()
test_s2.sort()
if (test_s1 != test_s2):
    flag = False
if (flag):
    print('YES')
else:
    print('NO')
