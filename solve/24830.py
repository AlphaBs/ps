# https://www.acmicpc.net/problem/24830

n = int(input())
result = 1

for i in range(n):
    s = input().split()

    a = int(s[0])
    op = s[1]
    b = int(s[2])

    if op == '+':
        result = (a + b) - result
    if op == '-':
        result = result * (a - b)
    if op == '*':
        result = (a * b) * (a * b)
    if op == '/':
        if a % 2 == 0:
            result = a // 2
        else:
            result = (a + 1) // 2

    print(result)