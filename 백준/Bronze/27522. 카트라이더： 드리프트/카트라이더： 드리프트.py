import sys

input = sys.stdin.readline

L = []
for i in range(8):
    a, b = input().split()
    a = list( map(int,a.split(":")))
    L.append(a + [b])
L.sort(key = lambda x : (x[0], x[1],x[2]))

score = [10,8,6,5,4,3,2,1]
r = 0
b = 0
for i in range(8):
    if(L[i][3] == 'B'):
        b+= score[i]
    else:
        r += score[i]
if(r>b):
    print('Red')
else:
    print('Blue')