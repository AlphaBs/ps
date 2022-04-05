dj = set()
bj = set()
n, m = map(int, input().split())
for i in range(n):
    dj.add(input())
for i in range(m):
    bj.add(input())

dbj = dj & bj
print(len(dbj))
print("\n".join(sorted(list(dbj))))