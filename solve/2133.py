# https://www.acmicpc.net/problem/2133

import sys
sys.setrecursionlimit(111_111)
n = int(input())

dp = [[-1] * 2 for i in range(55)]
def solve(n, complete):
    if n == 0:
        return complete    
    if dp[n][complete] != -1:
        return dp[n][complete]
    
    if complete:
        res = 3 * solve(n - 2, 1)
        if n >= 3:
            res += solve(n - 2, 0) * 2
    else:
        res = solve(n - 2, 1) + solve(n - 2, 0)
    dp[n][complete] = res
    return res

if n % 2 == 0:
    print(solve(n, 1))
else:
    print(0)