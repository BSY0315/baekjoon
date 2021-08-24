count = int(input())
time_list = list(map(int, input().split()))
time_list.sort()

sum = 0
list_count = len(time_list)
for index, item in enumerate(time_list):
    sum += item * (list_count - index)

print(sum)
