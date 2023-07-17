s = input()
L = s.split('.')

ans = ''
flag = 0

for i in range(len(L)):
    target = L[i]
    if(len(target) == 4):
        ans = ans + 'AAAA'
    elif(len(target) == 2):
        ans = ans + 'BB'
    elif(len(target) > 4):
        if(len(target) % 2 == 1):
            flag = 1
            break
        for j in range(len(target) // 4):
            ans = ans + 'AAAA'
        ans = ans + 'B' * int(len(target) % 4)
    else:
        if(len(target) != 0):
            flag = 1
            break
    ans = ans + '.'
if(flag):
    print(-1)
else:
    print(ans[:-1])