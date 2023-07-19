a,b = map(int,input().split())
a_list = set(list(map(int,input().split())))
b_list = set(list(map(int,input().split())))

print(len(a_list - b_list) + len(b_list - a_list))