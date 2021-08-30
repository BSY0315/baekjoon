N, M = map(int, input().split())
list = [0 for _ in range(0, M + 1)]
isVisit = [False for _ in range(0, N + 1)]


def recursive(depth):
    if depth == M:
        print(*list[:-1], sep=" ")
        return
    for i in range(1, N + 1):
        if not isVisit[i] and list[depth - 1] < i:
            isVisit[i] = True
            list[depth] = i
            recursive(depth + 1)
            isVisit[i] = False


recursive(0)
