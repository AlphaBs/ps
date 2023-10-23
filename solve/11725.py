# https://www.acmicpc.net/problem/11725

import sys
sys.setrecursionlimit(222_222)
n = int(sys.stdin.readline())
connections = [set() for i in range(n + 5)]
for i in range(n - 1):
    a, b = map(int, sys.stdin.readline().split())
    connections[a].add(b)
    connections[b].add(a)

parents = [0]*(n + 5)
def dfs(start, parent):
    parents[start] = parent
    for connected in connections[start]:
        if connected == parent:
            continue
        dfs(connected, start)

dfs(1, 0)
for i in range(2, n + 1):
    print(parents[i])