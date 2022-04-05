class Period:
    def __init__(self, a, b):
        self.a = a
        self.b = b
    
lst = list()
n = int(input())
for i in range(n):
    a, b = map(int, input().split())
    lst.append(Period(a, b))

lst.sort(key=lambda x: (x.b, x.a))

count = 1
lastb = lst[0].b
for i in range(1, n):
    if lst[i].a < lastb:
        continue
    #print(lst[i].a, lst[i].b)
    lastb = lst[i].b
    count += 1

print(count)