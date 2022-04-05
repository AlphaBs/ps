lst = list()
poke = dict()
n, m = map(int, input().split())

for i in range(n):
    inp = input()
    lst.append(inp)
    poke[inp] = i + 1

for i in range(m):
    inp = input()
    if inp.isnumeric():
        print(lst[int(inp) - 1])
    else:
        print(poke[inp])
