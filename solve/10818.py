input()
ins = input().split()
min = int(ins[0])
max = int(ins[0])
for i in ins:
    x = int(i)
    if (x < min):
        min = x
    if (x > max):
        max = x
print(min, max)