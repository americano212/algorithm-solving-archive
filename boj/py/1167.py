from collections import deque
import sys
input = sys.stdin.readline

def bfs(node, type):
    queue = deque([node])
    dp = [-1 for _ in range(v+1)]
    dp[node] = 0
    while(queue):
        now = queue.popleft()
        for next, distance in L[now]:
            if(dp[next] == -1):
                dp[next] = dp[now] + distance
                queue.append(next)
    if(type == 1):
        return dp.index(max(dp))
    else:
        return max(dp)

v = int(input())
L = [[] for _ in range(v+1)]
for _ in range(v):
    tmp = list(map(int,input().split()))
    a = tmp[0]
    for i in range(1, len(tmp)//2):
        b = tmp[i * 2 - 1]
        distance = tmp[i * 2]
        L[a].append([b, distance])
print(bfs(bfs(1, 1), 0))