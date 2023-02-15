import sys
import copy
from collections import deque
from math import inf

sys.setrecursionlimit(100000)

input = sys.stdin.readline


def solve(L):
    global score
    n = len(L[0])

    if (n == 1):
        score[L[0][0]] += 1
        return
    flag = False
    init = L[0][0]
    for i in range(n):
        for j in range(n):
            if (L[i][j] != init):
                flag = True
                break
        if (flag):
            break
    if (flag):
        div_3 = int(n / 3)
        for i in range(3):
            for j in range(3):
                next_L = []
                for k in range(i * div_3, (i + 1) * div_3):
                    temp = []
                    for l in range(j * div_3, (j + 1) * div_3):
                        temp.append(L[k][l])
                    next_L.append(temp)
                solve(next_L)
    else:
        score[init] += 1
        return


n = int(input())
L = []
for i in range(n):
    L.append(list(map(int, input().split())))

score = [0, 0, 0]
solve(L)
print(score[-1])
print(score[0])
print(score[1])
