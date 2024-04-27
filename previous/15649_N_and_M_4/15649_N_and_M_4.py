# https://www.acmicpc.net/problem/15652
# 15652 - N 과 M 4
N, M = map(int, input().split())
list = [0 for _ in range(0, M + 1)]


def recursive(depth):
    if depth == M:
        print(*list[:-1], sep=" ")
        return
    for i in range(1, N + 1):
        if i >= list[depth - 1]:
            list[depth] = i
            recursive(depth + 1)


recursive(0)
