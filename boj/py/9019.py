from collections import deque
import sys
input = sys.stdin.readline


t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    queue = deque()
    queue.append((a, ""))
    visit = [False] * 10000

    while (queue):
        now, history = queue.popleft()
        visit[now] = True
        if (now == b):
            print(history)
            break

        d = (2 * now) % 10000
        if not visit[d]:
            queue.append((d, history+"D"))
            visit[d] = True
        s = (now - 1) % 10000
        if not visit[s]:
            queue.append((s, history+"S"))
            visit[d] = True
        l = (10*now+(now//1000)) % 10000
        if not visit[l]:
            queue.append((l, history+"L"))
            visit[d] = True
        r = (now//10+(now % 10)*1000) % 10000
        if not visit[r]:
            queue.append((r, history+"R"))
            visit[d] = True
