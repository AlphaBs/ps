# https://www.acmicpc.net/problem/1737

import sys
import math
sys.setrecursionlimit(111_111)
n = int(sys.stdin.readline())

dp = [[-1] * 1111 for i in range(1111)]

def p(a, b):
    if dp[a][b] != -1:
        return dp[a][b]

    i = n - a - b * math.pi
    if i >= 0 and i <= math.pi:
        res = 1
    else:
        res = p(a + 1, b) + p(a, b + 1) 
    dp[a][b] = res % 1_000_000_000_000_000_000
    return dp[a][b]
    
print(p(0, 0))