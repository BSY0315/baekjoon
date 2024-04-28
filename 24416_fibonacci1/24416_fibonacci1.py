# https://www.acmicpc.net/problem/1912

n = int(input())

count = 0

def fib(n):
    global count
    if (n == 1 or n == 2):
        count =  count + 1
        return 1;
    else:
        return (fib(n-1) + fib(n-2))

fib(n)
print(count, n-2)