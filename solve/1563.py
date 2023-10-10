# https://www.acmicpc.net/problem/1563

import sys
sys.setrecursionlimit(1111)
n = int(sys.stdin.readline())
dp = [ [ [0] * 3 for i in range(3) ] for j in range(1111) ]

REM = 1_000_000

def solve(d, l, a):
    if l >= 2:
        return 0
    if a >= 3:
        return 0
    if d == 0:
        return 1
    
    if dp[d][l][a] != 0:
        return dp[d][l][a]

    res = solve(d - 1, l, 0) + \
          solve(d - 1, l + 1, 0) + \
          solve(d - 1, l, a + 1)
    dp[d][l][a] = res % REM
    return res % REM

sys.stdout.write(str(solve(n, 0, 0)))