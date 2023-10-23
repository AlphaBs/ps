# https://www.acmicpc.net/problem/13549

import sys
import heapq
n, k = map(int, sys.stdin.readline().split())

q = []
heapq.heappush(q, (n, 0))
distances = [999_999_999] * (333_333)
distances[n] = 0

while q:
    node, totalDistance = heapq.heappop(q)
    if totalDistance > distances[node]:
        continue
    for nextNode, nextDistance in [(node*2, 0), (node+1, 1), (node-1, 1)]:
        nextTotalDistance = totalDistance + nextDistance
        if nextNode >= 0 and nextNode <= 222_222 and nextTotalDistance < distances[nextNode]:
            distances[nextNode] = nextTotalDistance
            heapq.heappush(q, (nextNode, nextTotalDistance))

print(distances[k])