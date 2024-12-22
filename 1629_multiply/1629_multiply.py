# https://www.acmicpc.net/problem/1629

import sys

input = sys.stdin.readline


def divide(A, N, C):
    if (N == 1):
        return A % C

    answer = divide(A, N//2, C) % C
    return ((answer * answer) * (1 if N % 2 == 0 else A)) % C


A, B, C = map(int, input().split())
answer = divide(A % C, B, C)
print(answer)

# (A * B) % C = (A%C * B%C)
