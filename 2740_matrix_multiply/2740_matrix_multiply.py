import sys

input = sys.stdin.readline

N, M = map(int, input().split())

first_matrix = [[0 for _ in range(M)] for _ in range(N)]
for i in range(N):
    first_matrix[i] = list(map(int, input().split()))

M, K = map(int, input().split())

second_matrix = [[0 for _ in range(K)] for _ in range(M)]
for i in range(M):
    second_matrix[i] = list(map(int, input().split()))

third_matrix = [[0 for _ in range(K)] for _ in range(N)]

for i in range(N):
    for j in range(K):
        for k in range(M):
            third_matrix[i][j] += first_matrix[i][k] * second_matrix[k][j]


for item in third_matrix:
    for item_2 in item:
        print(item_2, end=" ")
    print("")
