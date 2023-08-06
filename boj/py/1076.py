s = '''
black	0	1
brown	1	10
red	2	100
orange	3	1,000
yellow	4	10,000
green	5	100,000
blue	6	1,000,000
violet	7	10,000,000
grey	8	100,000,000
white	9	1,000,000,000
'''
s = s.split('\n')[1:-1]

D = dict()
for i in range(len(s)):
    a,b,c = s[i].split('\t')
    D[a] = [b.replace(',',''), int(c.replace(',',''))]

s1 = input()
s2 = input()
s3 = input()
result = ''
result += D[s1][0]
result += D[s2][0]
result = int(result)
result *= D[s3][1]
print(result)