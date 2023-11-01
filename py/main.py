# https://www.acmicpc.net/problem/2525

import sys
sys.setrecursionlimit(111_111)

a, b = map(int, sys.stdin.readline().split())
c = int(sys.stdin.readline())

b += c

a += b // 60
a %= 24
b %= 60

print(a, b)
