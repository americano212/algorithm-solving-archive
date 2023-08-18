import sys
input = sys.stdin.readline


def BS(arr, target):
    L = 0
    R = len(arr) - 1
    while (L <= R):
        M = (L+R) // 2
        if (arr[M] == target):
            return 1
        if (arr[M] < target):
            L = M+1
        else:
            R = M-1
    return 0


N = int(input())
A = list(map(int, input().split()))
M = int(input())
check = list(map(int, input().split()))
A.sort()

for target in check:
    print(BS(A, target))
