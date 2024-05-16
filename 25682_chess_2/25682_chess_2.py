# https://www.acmicpc.net/problem/25682
import sys

N, M, K = map(int, input().split())

chess_board_w = ['' for _ in range(N)]
chess_board_b = ['' for _ in range(N)]
for i in range(N):
    string = input()
    if (i % 2 == 0):
        chess_board_w[i] = list('B' + string)
        chess_board_b[i] = list('W' + string)
    else:
        chess_board_w[i] = list('W' + string)
        chess_board_b[i] = list('B' + string)


dp_w = [[0 for _ in range(M+1)] for _ in range(N+1)]
for i in range(1, N+1):
    for j in range(1, M + 1):
        if chess_board_w[i-1][j] == chess_board_w[i-1][j-1]:
            chess_board_w[i-1][j] = 'B' if chess_board_w[i -
                                                         1][j] == 'W' else 'W'
            dp_w[i][j] = dp_w[i][j-1] + dp_w[i-1][j] - dp_w[i-1][j-1] + 1
        else:
            dp_w[i][j] = dp_w[i][j-1] + dp_w[i-1][j] - dp_w[i-1][j-1]

dp_b = [[0 for _ in range(M+1)] for _ in range(N+1)]
for i in range(1, N+1):
    for j in range(1, M + 1):
        if chess_board_b[i-1][j] == chess_board_b[i-1][j-1]:
            chess_board_b[i-1][j] = 'B' if chess_board_b[i -
                                                         1][j] == 'W' else 'W'
            dp_b[i][j] = dp_b[i][j-1] + dp_b[i-1][j] - dp_b[i-1][j-1] + 1
        else:
            dp_b[i][j] = dp_b[i][j-1] + dp_b[i-1][j] - dp_b[i-1][j-1]

count = sys.maxsize

for i in range(1, N - K + 2):
    for j in range(1, M - K + 2):
        count = min(count, dp_b[i+K-1][j+K-1] - dp_b[i+K-1][j-1] -
                    dp_b[i-1][j+K-1] + dp_b[i-1][j-1],
                    dp_w[i+K-1][j+K-1] - dp_w[i+K-1][j-1] -
                    dp_w[i-1][j+K-1] + dp_w[i-1][j-1])
print(count)
