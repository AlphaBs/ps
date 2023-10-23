# https://www.acmicpc.net/problem/13549

import sys
from collections import deque
n, k = map(int, sys.stdin.readline().split())

def solve(n):
    dist = [999_999] * 222_222
    dist[n] = 0

    q = deque()
    q.append(n)

    while q:
        pos = q.popleft()
        #print(pos)
        if pos == k:
            return dist[pos]
        
        if pos < k and dist[pos * 2] > dist[pos]:
            dist[pos * 2] = dist[pos]
            q.appendleft(pos * 2)
        if pos < k and dist[pos + 1] > dist[pos] + 1:
            dist[pos + 1] = dist[pos] + 1
            q.append(pos + 1)
        if pos > 0 and dist[pos - 1] > dist[pos] + 1:
            dist[pos - 1] = dist[pos] + 1
            q.append(pos - 1)

print(solve(n))