# https://www.acmicpc.net/problem/11660

N, M = map(int, input().split())
numbers = [[] for _ in range(N)]

for i in range(N):
    numbers[i] = list(map(int, input().split()))

dp = [[0 for _ in range(N+1)] for _ in range(N)]

for i in range(N):
    for j in range(1, N + 1):
        dp[i][j] = dp[i][j-1] + numbers[i][j-1]

answers = []
for i in range(M):
    start_y, start_x, end_y, end_x = list(map(int, input().split()))
    sum = 0
    for j in range(start_y - 1, end_y):
        sum += dp[j][end_x] - dp[j][start_x-1]
    answers.append(sum)

for item in answers:
    print(item)
