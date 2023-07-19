t = int(input())
def is_inner(x,y,c1,c2,r):
    distance = (x - c1) * (x - c1) + (y - c2) * (y - c2)
    if(r*r > distance):
        return True
    else:
        return False

for _ in range(t):
    x1, y1, x2, y2 = map(int,input().split())
    n = int(input())
    cnt = 0 
    for i in range(n):
        c1,c2,r = map(int,input().split())
        start_inner = is_inner(x1, y1, c1,c2,r)
        end_inner = is_inner(x2, y2, c1,c2,r)
        xor_start_end = start_inner ^ end_inner

        if(xor_start_end):
            cnt += 1
    print(cnt)