# https://www.acmicpc.net/problem/1535

import sys
sys.setrecursionlimit(111_111_111)
n = int(sys.stdin.readline())
costs = list(map(int, sys.stdin.readline().split()))
values = list(map(int, sys.stdin.readline().split()))

dp = [[-1] * 111 for i in range(111)]

def solve(i, cost):
    if cost <= 0:
        return -999_999
    if i == n:
        return 0
    if dp[i][cost] != -1:
        return dp[i][cost]
    dp[i][cost] = max(solve(i + 1, cost), solve(i + 1, cost - costs[i]) + values[i])
    return dp[i][cost]


print(solve(0, 100))