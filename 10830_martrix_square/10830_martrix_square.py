# https://www.acmicpc.net/problem/10830

import sys

input = sys.stdin.readline


def multiply(matrix_1, matrix_2, N, none=False):
    if none:
        return matrix_1

    second_matrix = [[0 for _ in range(N)] for _ in range(N)]
    for i in range(N):
        for j in range(N):
            for k in range(N):
                second_matrix[i][j] += matrix_1[i][k] * matrix_2[k][j]
            second_matrix[i][j] %= 1000

    return second_matrix


def divide_and_conquer(matrix, B, N):
    if (B == 1):
        for i in range(N):
            for j in range(N):
                matrix[i][j] %= 1000
        return matrix
    result = divide_and_conquer(matrix, B//2, N)
    return multiply(multiply(result, result, N), matrix, N, B % 2 == 0)


N, B = map(int, input().split())

matrix = [[0 for _ in range(N)] for _ in range(N)]
for i in range(N):
    matrix[i] = list(map(int, input().split()))

result = divide_and_conquer(matrix, B, N)
for i in range(N):
    for j in range(N):
        print(result[i][j], end=" ")
    print("")
