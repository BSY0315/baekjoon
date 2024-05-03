# https://www.acmicpc.net/problem/9251

a = input()
b = input()

dp = [[0 for _ in range(1005)] for _ in range(1005)]

for i, v_a in enumerate(a):
    for j, v_b in enumerate(b):
        if (v_a == v_b):
            dp[i + 1][j+1] = dp[i][j] + 1
        else:
            dp[i + 1][j+1] = max(dp[i][j + 1], dp[i + 1][j])

print(max(max(dp)))
