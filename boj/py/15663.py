n,m = map(int,input().split())
L = list(map(int,input().split()))
L.sort()
visit = []

def dfs():
    if(len(visit) == m):
        result.append(' '.join(map(str, visit)))
        return
    for item in L:
        if(visit == []):
            visit.append(item)
            dfs()
            visit.pop()
        else:
            if(visit.count(item) != L.count(item)):
                visit.append(item)
                dfs()
                visit.pop()

result = []
dfs()

result = list(set(result))
result_int = []
for item in result:
    result_int.append(list(map(int, item.split())))
result_int.sort()
for prt in result_int:
    print(*prt)