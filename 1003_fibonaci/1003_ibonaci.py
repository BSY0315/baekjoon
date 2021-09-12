# https://www.acmicpc.net/problem/1003
# 1003번 - 피보나치 함수
count = int(input())

fibonacci_list = [0 for _ in range(42)]
fibonacci_list[0] = 1
fibonacci_list[2] = 1
fibonacci_list[3] = 1
for i in range(4, 42):
    fibonacci_list[i] = fibonacci_list[i - 2] + fibonacci_list[i-1]

for _ in range(count):
    a = int(input())
    print(f"{fibonacci_list[a]} {fibonacci_list[a + 1]}")


'''
zero = 0
one = 0

def fibonacci(n: int) -> int:
    global zero
    global one
    if n == 0:
        # print("0")
        zero += 1
        return 0
    elif n == 1:
        # print("1")
        one += 1
        return 1
    else:
        return fibonacci(n-1) + fibonacci(n-2)


fibonacci(count)
print(f"{zero} {one}")
'''
