from collections import deque
import math

def find_alpha_range(n): # 0은 못거름
    if(n <= 0):
        return 0
    alpha = math.log2(100000/n)
    alpha = int(round(alpha, 0))
    return alpha
    

n, k = map(int, input().split())
visit = [False] * 100001
queue = deque()


for alpha in range(find_alpha_range(n) + 1):
    if(n * (2**alpha) > 100000):
        break
    queue.append([n * (2**alpha), 0])
# print(queue)
while(queue):
    now, time = queue.popleft()
    if(now == k):
        print(time)
        break
    if(visit[now] == True):
        continue
    visit[now] = True
    for alpha in range(find_alpha_range(now - 1) + 1):
        if((now - 1) * (2**alpha) > 100000):
            break
        queue.append([(now - 1) * (2**alpha), time + 1])
    for alpha in range(find_alpha_range(now + 1) + 1):
        if((now + 1) * (2**alpha) > 100000):
            break
        queue.append([(now + 1) * (2**alpha), time + 1])
    # print(now, time)
    # print(queue)
    # break