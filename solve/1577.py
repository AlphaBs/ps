# https://www.acmicpc.net/problem/1577

import sys

DIRECTION_X = 0
DIRECTION_Y = 1

blockedRoad = [[[False] * 2 for i in range(111)] for j in range(111)]

def dydxToDirection(dy, dx):
    if dy == 1:
        return DIRECTION_Y
    if dx == 1:
        return DIRECTION_X
    
def isBlocked(y, x, direction):
    return blockedRoad[y][x][direction]

n, m = map(int, sys.stdin.readline().split())
k = int(sys.stdin.readline())
for i in range(k):
    a, b, c, d = map(int, sys.stdin.readline().split())
    startX = min(a, c)
    startY = min(b, d)
    dx = abs(a - c)
    dy = abs(b - d)
    blockedRoad[startY][startX][dydxToDirection(dy, dx)] = True

dp = [[-1] * 111 for i in range(111)]
def solve(y, x):
    if y == m and x == n:
        return 1
    if y < 0 or y > m or x < 0 or x > n:
        return 0
    
    if dp[y][x] != -1:
        return dp[y][x]

    resX = solve(y, x + 1) if not isBlocked(y, x, DIRECTION_X) else 0
    resY = solve(y + 1, x) if not isBlocked(y, x, DIRECTION_Y) else 0
    dp[y][x] = resX + resY
    return dp[y][x]

print(solve(0, 0))