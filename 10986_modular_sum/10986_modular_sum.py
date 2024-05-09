# https://www.acmicpc.net/problem/10986

N, M = map(int, input().split())
lists = list(map(int, input().split()))

dp = [0 for _ in range(N + 1)]
cnt = [0 for _ in range(M)]

for i in range(1, N + 1):
    dp[i] = dp[i-1] + lists[i-1]

for i in range(N + 1):
    cnt[dp[i] % M] += 1

sum = 0
for i in range(M):
    sum += cnt[i] * (cnt[i] - 1) // 2

print(sum)
