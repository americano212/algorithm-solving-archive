s = list(input())

stack = []
result = ''

for i in range(len(s)):
    now = s[i]
    if (now.isalpha()):
        result += now
    else:
        if (now == '('):
            stack.append(now)
        elif (now == '*' or now == '/'):
            while (len(stack) != 0 and (stack[-1] == '*' or stack[-1] == '/')):
                result += stack.pop()
            stack.append(now)
        elif (now == '+' or now == '-'):
            while (len(stack) != 0 and stack[-1] != '('):
                result += stack.pop()
            stack.append(now)
        elif (now == ')'):
            while (len(stack) != 0 and stack[-1] != '('):
                result += stack.pop()
            stack.pop()

stack.reverse()
print(result + ''.join(stack))
