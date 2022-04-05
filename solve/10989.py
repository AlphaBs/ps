n = int(input())
lst = list()
for i in range(n):
    lst.append(int(input()))

lst.sort()

for i in lst:
    print(i)