s = list(input())

stack = []
while (s):
    now = s.pop()
    if (now == '('):
        result = ''
        while (True):
            before = stack.pop()
            if (before == ')'):
                break
            result += before
        keep = ''
        result_L = []
        for i in range(len(result)):
            now_r = result[i]
            if (now_r == '+' or now_r == '-'):
                keep = now_r
                continue
            if (keep != ''):
                result_L.append(now_r + keep)
            else:
                result_L.append(now_r)

        stack.append(''.join(result_L))

        if (len(stack) != 0):
            if (stack[-1] == '*' or stack[-1] == '/'):
                before = stack.pop()
                before_before = stack.pop()
                result = now + before_before + before
                stack.append(result)
    elif (now == ')'):
        stack.append(now)
    elif (len(stack) != 0):
        if (stack[-1] == '*' or stack[-1] == '/'):
            before = stack.pop()
            before_before = stack.pop()
            result = now + before_before + before
            stack.append(result)
        else:
            stack.append(now)
    else:
        stack.append(now)
    # print(stack)
final = []
for i in range(len(stack)):
    final_r = stack[i]
    if (final_r == '-' or final_r == '+'):
        before = final.pop()
        final.append(before+final_r)
    else:
        final.append(final_r)

final.reverse()
print(''.join(final))
