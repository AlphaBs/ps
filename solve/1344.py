# https://www.acmicpc.net/problem/1344

primes = [2,3,5,7,11,13,17,19]
primeMap = [False] * 20
for p in primes:
    primeMap[p] = True

def isPrime(num):
    return primeMap[num]

probA = float(input()) / 100
probB = float(input()) / 100

dp = [[[-1] * 22 for i in range(22)] for j in range(22)]
def solve(play, scoreA, scoreB):
    if play > 18:
        if isPrime(scoreA) or isPrime(scoreB):
            return 1.0
        else:
            return 0.0

    if dp[play][scoreA][scoreB] != -1:
        return dp[play][scoreA][scoreB]
    
    prob = 0
    prob += solve(play + 1, scoreA, scoreB) * (1-probA) * (1-probB)
    prob += solve(play + 1, scoreA + 1, scoreB) * probA * (1-probB)
    prob += solve(play + 1, scoreA, scoreB + 1) * (1-probA) * probB
    prob += solve(play + 1, scoreA + 1, scoreB + 1) * probA * probB
    dp[play][scoreA][scoreB] = prob
    return prob

result = solve(1, 0, 0)
print(f'{result:.10f}')