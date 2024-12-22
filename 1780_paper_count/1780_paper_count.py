
# https://www.acmicpc.net/problem/1780

minus_one = 0
zero = 0
one = 0


def divide(paper, N):
    global minus_one
    global zero
    global one

    is_minus_one = True
    is_zero = True
    is_one = True

    for i in range(N):
        for j in range(N):
            if (paper[i][j] != -1):
                is_minus_one = False
            if (paper[i][j] != 0):
                is_zero = False
            if (paper[i][j] != 1):
                is_one = False

    if (is_minus_one):
        minus_one += 1
        return
    if (is_zero):
        zero += 1
        return
    if (is_one):
        one += 1
        return

    divided_num = N//3

    divide([row[0:divided_num] for row in paper[0:divided_num]], divided_num)
    divide([row[divided_num:divided_num*2]
           for row in paper[0:divided_num]], divided_num)
    divide([row[divided_num*2:divided_num*3]
           for row in paper[0:divided_num]], divided_num)

    divide([row[0:divided_num]
           for row in paper[divided_num:divided_num*2]], divided_num)
    divide([row[divided_num:divided_num*2]
           for row in paper[divided_num:divided_num*2]], divided_num)
    divide([row[divided_num*2:divided_num*3]
           for row in paper[divided_num:divided_num*2]], divided_num)

    divide([row[0:divided_num]
           for row in paper[divided_num*2:divided_num*3]], divided_num)
    divide([row[divided_num:divided_num*2]
           for row in paper[divided_num*2:divided_num*3]], divided_num)
    divide([row[divided_num*2:divided_num*3]
           for row in paper[divided_num*2:divided_num*3]], divided_num)


n = int(input())
paper = [[] for _ in range(n)]
for i in range(n):
    paper[i] = list(map(int, input().split()))


divide(paper, n)


print(minus_one)
print(zero)
print(one)
