jp_sum = 0
hj_sum = 0
for _ in range(20):
    s = input().split()
    if(s[2] == "P"):
        continue
    hj = float(s[1])
    hj_sum += hj
    temp_gp = 0
    if(s[2][0]=="A"):
        temp_gp += 4
    elif(s[2][0]=="B"):
        temp_gp += 3
    elif(s[2][0]=="C"):
        temp_gp += 2
    elif(s[2][0]=="D"):
        temp_gp += 1
    else:
        continue

    if(s[2][1] == '+'):
        temp_gp += 0.5
    
    jp_sum += temp_gp * hj

print(jp_sum / hj_sum)