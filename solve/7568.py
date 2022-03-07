class Body:
    def __init__(self, w, h):
        self.w = w
        self.h = h
    
    def isBiggerThen(self, b):
        return b.w > self.w and b.h > self.h

lst = list()
n = int(input())
for i in range(n):
    w, h = map(int, input().split())
    lst.append(Body(w, h))

for i in range(n):
    count = 0
    for j in range(n):
        if lst[i].isBiggerThen(lst[j]):
            count += 1
    print(count + 1, end=' ')
