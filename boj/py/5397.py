t = int(input())
for _ in range(t):
    strn = input()
    ans = []
    stack = []
    for s in strn:
        if s == '<':
            if len(ans) != 0:
                tmp = ans.pop()
                stack.append(tmp)
        elif s == '>':
            if len(stack) != 0:
                tmp = stack.pop()
                ans.append(tmp)
        elif s == '-':
            if len(ans) != 0:
                ans.pop()
        else:
            ans.append(s)
    ans += stack[::-1]
    print(''.join(ans))
