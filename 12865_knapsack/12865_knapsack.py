N, K = map(int, input().split())

lists = [{'weight': 0, 'value': 0} for _ in range(N + 1)]
for i in range(1, N + 1):
    W, V = map(int, input().split())
    lists[i] = {'weight': W, 'value': V}

dp = [[0 for _ in range(K + 1)] for _ in range(N + 1)]

for i in range(1, N + 1):
    for j in range(1, K + 1):
        if j < lists[i]['weight']:
            dp[i][j] = dp[i-1][j]
        else:
            dp[i][j] = max(dp[i-1][j], lists[i]['value'] +
                           dp[i-1][j - lists[i]['weight']])

print(max(max(dp)))
