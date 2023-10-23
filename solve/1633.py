# https://www.acmicpc.net/problem/1633

import sys
scores = []
for line in sys.stdin:
    white, black = map(int, line.split())
    scores.append((white, black))

dp = [[[-1] * 1111 for i in range(16)] for j in range(16)]
def solve(player, white, black):
    if player >= len(scores):
        if white == 15 and black == 15:
            return 0
        else:
            return -9999
    
    if dp[white][black][player] != -1:
        return dp[white][black][player]

    whiteScore, blackScore = scores[player]
    res = solve(player + 1, white, black)
    if white < 15:
        res = max(res, solve(player + 1, white + 1, black) + whiteScore)
    if black < 15:
        res = max(res, solve(player + 1, white, black + 1) + blackScore)
    dp[white][black][player] = res
    return res

print(solve(0, 0, 0))