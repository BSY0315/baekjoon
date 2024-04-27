# https://www.acmicpc.net/problem/11399
# 11399 - ATM
count = int(input())
time_list = list(map(int, input().split()))
time_list.sort()

sum = 0
list_count = len(time_list)
for index, item in enumerate(time_list):
    sum += item * (list_count - index)

print(sum)
