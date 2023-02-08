n = int(input())
L = list(map(int,input().split()))
pre_fix_sum = [0]

for i in range(len(L)):
    new_prefix_sum = pre_fix_sum[-1]+L[i]
    if(new_prefix_sum < L[i]):
        pre_fix_sum.append(L[i])
    else:
        pre_fix_sum.append(new_prefix_sum)

print(max(pre_fix_sum[1:]))