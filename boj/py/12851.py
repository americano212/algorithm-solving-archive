from collections import deque
# https://www.acmicpc.net/problem/12851
n, k = map(int, input().split())

queue = deque()

queue.append([n, 0])
time_save = -1
cnt = 0

while(queue):
    now, time = queue.popleft()
    if(now == k):
        if(time_save == -1):
            time_save = time
        if(time_save == time):
            cnt += 1
    if(time > time_save and time_save != -1):
        break
    if(time_save == -1):
        if(now != 0):
            if(now-1 == k):
                queue.append([now-1, time + 1])
            elif([now-1, time + 1] not in queue):
                queue.append([now-1, time + 1])
        if(now!=100000):
            if(now+1 == k):
                queue.append([now+1, time + 1])
            elif([now+1, time + 1] not in queue):
                queue.append([now+1, time + 1])
        if(now * 2 <= 100000):
            if(now*2 == k):
                queue.append([now*2, time + 1])
            elif([now*2, time + 1] not in queue):
                queue.append([now*2, time + 1])
    # print(now, time)
    # print(queue)

    # if(time == 3):
    #     break

print(time_save)
print(cnt)