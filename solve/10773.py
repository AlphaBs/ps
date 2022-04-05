k = int(input())
lst = list()
for i in range(k):
    inp = int(input())
    if inp == 0:
        lst.pop()
    else:
        lst.append(inp)

sum = 0
for i in lst:
    sum += i
print(sum)