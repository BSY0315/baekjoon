# https://www.acmicpc.net/problem/9461
# 9461번 - 파도반 수열

dp = [0 for _ in range(101)]
dp[0] = 1
dp[1] = 1
dp[2] = 1
dp[3] = 2
dp[4] = 2
dp[5] = 3
dp[6] = 4
dp[7] = 5

for i in range(7, 100):
    dp[i+1] = dp[i] + dp[i-4]

testcaseCount = int(input())

for _ in range(testcaseCount):
    print(dp[int(input())-1])
