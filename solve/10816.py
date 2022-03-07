input()
d = dict()
for inp in input().split():
    if inp in d:
        d[inp] = d[inp] + 1
    else:
        d[inp] = 1
input()
for inp in input().split():
    if inp in d:
        print(d[inp], end=" ")
    else:
        print("0", end=" ")