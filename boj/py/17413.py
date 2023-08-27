strn = list(input())
stack = []
result = ""
temp = ""
for s in strn:
    if (s == "<"):
        if temp != '':
            temp_result = []
            temp_L = temp.split()
            for i in range(len(temp_L)):
                now_s = temp_L[i]
                now_s = list(now_s)
                now_s.reverse()
                temp_result.append(''.join(now_s))
            result += ' '.join(temp_result)
            temp = ''
        result += s
        stack.append(s)
    elif s == '>':
        result += s
        stack.pop()
    else:
        if stack:
            result += s
        else:
            temp += s
if temp != '':
    temp_result = []
    temp_L = temp.split()
    for i in range(len(temp_L)):
        now_s = temp_L[i]
        now_s = list(now_s)
        now_s.reverse()
        temp_result.append(''.join(now_s))
    result += ' '.join(temp_result)
print(result)
