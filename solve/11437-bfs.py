# https://www.acmicpc.net/problem/11437

import sys
from collections import deque
sys.setrecursionlimit(111_111)

n = int(sys.stdin.readline())
graph = [[] for i in range(55555)]
for i in range(n-1):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

depths = [0] * 55555
parents = [None] * 55555
visited = [False] * 55555
def initNodes(node):
    q = deque([node])
    visited[node] = True
    while q:
        node = q.popleft()
        for connected in graph[node]:
            if not visited[connected]:
                depths[connected] = depths[node] + 1
                parents[connected] = node
                visited[connected] = True
                q.append(connected)
initNodes(1)

def lca(a, b):
    if depths[a] > depths[b]:
        return lca(b, a)
    
    while depths[a] < depths[b]:
        b = parents[b]
    while a != b:
        a = parents[a]
        b = parents[b]
    return a

m = int(sys.stdin.readline())
for i in range(m):
    a, b = map(int, sys.stdin.readline().split())
    sys.stdout.write(str(lca(a, b)) + "\n")