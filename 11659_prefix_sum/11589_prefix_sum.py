# https://www.acmicpc.net/problem/11589

N, M = map(int, input().split())
lists = list(map(int, input().split()))

dp = [0 for _ in range(N + 1)]

for i in range(1, N + 1):
    dp[i] = dp[i-1] + lists[i-1]

answers = [0 for _ in range(M)]
for i in range(M):
    start, end = map(int, input().split())
    answers[i] = dp[end]-dp[start-1]

for item in answers:
    print(item)
