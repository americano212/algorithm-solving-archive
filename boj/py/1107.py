import sys
input=sys.stdin.readline

n = int(input())
m = int(input())
broken = set()
if(m!=0):
    broken = set(list(map(str,input().split())))
ans = 1000000
for channel in range(1000001):
    if(len(set(list(str(channel))) & broken) != 0):
        continue
    btn = len(str(channel))
    btn += min(abs(n - 100), abs(n - channel))
    ans = min(ans, btn)
    # if(ans == 344451):
    #     print(channel)
    #     break
ans = min(ans, abs(n-100))
print(ans)