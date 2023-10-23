# https://www.acmicpc.net/problem/1967

import sys

sys.setrecursionlimit(11111)
n = int(sys.stdin.readline())
tree = [[] for i in range(n + 1)]
for i in range(n-1):
    parent, child, weight = map(int, sys.stdin.readline().split())
    tree[parent].append([child,weight])

longest = 0
def solve(node):
    m1, m2 = 0, 0
    for child, weight in tree[node]:
        dist = solve(child) + weight
        if m1 <= m2:
            m1 = max(m1, dist)
        else:
            m2 = max(m2, dist)

    global longest
    longest = max(longest, m1 + m2)
    return max(m1, m2)

solve(1)
print(longest)