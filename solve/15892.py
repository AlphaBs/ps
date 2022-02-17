length = int(input())
inp = input()
r = 31
m = 1234567891
sum = 0
tempr = 1
for i in range(length):
    charval = ord(inp[i]) - 96
    sum += charval * tempr
    tempr *= r

print(str(sum % m))