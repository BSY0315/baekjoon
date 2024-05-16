# https://www.acmicpc.net/problem/2630

blue = 0
white = 0


def divide(paper, N):
    global blue
    global white

    is_blue = True
    is_white = True

    for i in range(N):
        for j in range(N):
            if (paper[i][j] != 0):
                is_white = False
            else:
                is_blue = False

    if (is_blue):
        blue += 1
        return
    if (is_white):
        white += 1
        return

    divide([row[0:N//2] for row in paper[0:N//2]], N//2)
    divide([row[N//2:N] for row in paper[0:N//2]], N//2)
    divide([row[0:N//2] for row in paper[N//2:N]], N//2)
    divide([row[N//2:N] for row in paper[N//2:N]], N//2)


n = int(input())
paper = [[] for _ in range(n)]
for i in range(n):
    paper[i] = list(map(int, input().split()))

divide(paper, n)

print(white)
print(blue)
