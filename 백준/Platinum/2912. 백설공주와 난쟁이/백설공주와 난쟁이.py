import sys
import random
input = sys.stdin.readline

def get(s, e, idx, A, B, num):
    if A <= s and e <= B:
        if num in L[idx]:
            return L[idx][num]
        else:
            return 0
    if e < A or B < s:
        return 0

    ans = 0
    mid = (s + e) // 2
    ans += get(s, mid, idx * 2, A, B, num)
    ans += get(mid + 1, e, idx * 2 + 1, A, B, num)
    return ans

def solve(s, e, idx):
    D = {}
    if s == e:
        D[K[s - 1]] = 1
        L[idx] = D
        return D

    mid = (s + e) // 2
    left = solve(s, mid, idx * 2)
    right = solve(mid + 1, e, idx * 2 + 1)

    for num in left:
        if num in D:
            D[num] += left[num]
        else:
            D[num] = left[num]

    for num in right:
        if num in D:
            D[num] += right[num]
        else:
            D[num] = right[num]

    L[idx] = D
    return D


N, C = map(int, input().split())
K = list(map(int, input().split()))
M = int(input())
L = [{} for _ in range(1050000)]
solve(1, N, 1)
for _ in range(M):
    A, B = map(int, input().split())
    check = (B - A + 1) // 2

    C = {}
    for _ in range(20):
        R = K[random.randint(A, B)-1]
        if R in C:
            continue
        else:
            C[R] = 1
        if get(1, N, 1, A, B, R) > check:
            print('yes', R)
            break
    else:
        print('no')
