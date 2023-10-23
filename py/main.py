# https://www.acmicpc.net/problem/1005

import sys
sys.setrecursionlimit(111_111)

t = int(sys.stdin.readline())
for i in range(t):
    n, k = map(int, sys.stdin.readline().split())
    d = list(map(int, sys.stdin.readline().split()))
    prerequisites = {}
    for j in range(k):
        x, y = map(int, sys.stdin.readline().split())
        if not y in prerequisites:
            prerequisites[y] = []
        prerequisites[y].append(x)
    w = int(sys.stdin.readline())

    dp = [-1] * 1111
    def solve(w):
        if dp[w] != -1:
            return dp[w]

        preTime = 0
        if w in prerequisites:
            for pre in prerequisites[w]:
                preTime = max(preTime, solve(pre))
        dp[w] = preTime + d[w - 1]
        return dp[w]
    sys.stdout.write(str(solve(w)) + "\n")