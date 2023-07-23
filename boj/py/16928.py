from collections import deque

n,m = map(int,input().split())

ladder = dict()
snake = dict()

for _ in range(n):
    a, b = map(int, input().split())
    ladder[a] = b
    
for _ in range(m):
    a, b = map(int, input().split())
    snake[a] = b



queue = deque([1])
visit = [False for _ in range(101)]
board = [0 for _ in range(101)]

while queue:
    now = queue.popleft()

    if(now == 100):
        print(board[now])
        break

    for dice in range(1,7):
        next = now + dice
        if(next <= 100 and visit[next] == False):
            if next in ladder.keys():
                next = ladder[next]
            elif next in snake.keys():
                next = snake[next]
            if visit[next] == False:
                visit[next] = True
                board[next] = board[now] + 1
                queue.append(next)