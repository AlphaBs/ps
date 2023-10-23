# https://www.acmicpc.net/problem/2225

import sys
sys.setrecursionlimit(111_111)
n, k = map(int, sys.stdin.readline().split())

dp = [[-1] * 222 for i in range(222)]
def solve(n, k):
    if n == 0 and k == 0:
        return 1
    if n < 0 or k < 0:
        return 0
    
    if dp[n][k] != -1:
        return dp[n][k]

    res = 0
    for i in range(0, n + 1):
        res += solve(n - i, k - 1)
        res %= 1_000_000_000
    dp[n][k] = res
    return res

print(solve(n, k))