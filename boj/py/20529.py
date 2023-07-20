import itertools

t = int(input())

kind = ['ISTJ', 'ISFJ', 'INFJ', 'INTJ', 'ISTP', 'ISFP', 'INFP', 'INTP', 'ESTP', 'ESFP', 'ENFP', 'ENTP', 'ESTJ', 'ESFJ', 'ENFJ', 'ENTJ']

def find_distance(a,b,c):
    result = 0
    for i in range(4):
        if(a[i]!=b[i]):
            result+=1
    for i in range(4):
        if(a[i]!=c[i]):
            result+=1
    for i in range(4):
        if(c[i]!=b[i]):
            result+=1

    return result

for _ in range(t):
    n = int(input())
    L = input().split()
    mbti_list = []
    for i in range(16):
        cnt = L.count(kind[i])
        if(cnt>3):
            cnt = 3
        mbti_list += [kind[i]] * cnt

    nCr = list(itertools.combinations(mbti_list, 3))
    #print("ncr",nCr)
    minimum = 10000
    for i in range(len(nCr)):
        minimum = min(find_distance(*nCr[i]),minimum)
    print(minimum)