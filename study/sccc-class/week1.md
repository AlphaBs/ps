11726 MOD 연산 주의
dp[i] = (dp[i - 2] % MOD + dp[i - 1]) % MOD;

1697 DP
짝수
dp[i] = min(dp[l - 1] + 1, dp[l / 2] + 1)
홀수
dp[i] = min(dp[l - 1] + 1, dp[(l + 1) / 2] + 2)

2133 DP 배열 하나만

9898 domino
2133 타일 채우기
