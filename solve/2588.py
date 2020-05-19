a = input()
b = input()

m1 = int(a) * int(b[2])
m2 = int(a) * int(b[1])
m3 = int(a) * int(b[0])
result = m1 + (m2 * 10) + (m3 * 100)

print(m1)
print(m2)
print(m3)
print(result)