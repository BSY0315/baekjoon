/* https://www.acmicpc.net/problem/1904 */
/* 1904번 - 01 타일 */
#include <stdio.h>
#include <limits.h>

#define CONSTANT 15746

int main(void)
{
    long long prev = 1LL;
    long long now = 2LL;

    int n;
    scanf("%d", &n);

    for (int i = 2; i < n; i++)
    {
        now = prev + now;
        prev = now - prev;

        now = now % CONSTANT;
        prev = prev % CONSTANT;
    }
    now = (n == 1) ? 1 : now;
    printf("%d", now % CONSTANT);
    return 0;
}

/* 나머지 연산 분배 법칙*/
// https://velog.io/@gidskql6671/%EB%82%98%EB%A8%B8%EC%A7%80Modulo-%EC%97%B0%EC%82%B0-%EB%B6%84%EB%B0%B0%EB%B2%95%EC%B9%99