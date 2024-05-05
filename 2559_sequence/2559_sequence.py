# https://www.acmicpc.net/problem/2259

N, K = map(int, input().split())
lists = list(map(int, input().split()))

dp = [0 for _ in range(N + 1)]

for i in range(1, N + 1):
    dp[i] = dp[i-1] + lists[i-1]

max = -100 * 100_001

for i in range(N-K + 1):
    start = i
    end = i+K
    answer = dp[end]-dp[start]
    if answer > max:
        max = answer

print(max)
