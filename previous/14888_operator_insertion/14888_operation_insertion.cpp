/* https://www.acmicpc.net/problem/14888
14888번 - 연산자 끼워넣기*/
#include <iostream>
#include <climits>

#define MAX (11)
#define OPERATOR_COUNT (4)

typedef long long int lld;

lld g_num_list[MAX] = {
    0,
};
int g_operator_count[OPERATOR_COUNT] = {
    0,
};
inline lld add(const lld a, const lld b) { return a + b; }
inline lld sub(const lld a, const lld b) { return a - b; }
inline lld mul(const lld a, const lld b) { return a * b; }
inline lld divide(const lld a, const lld b) { return a / b; }
lld (*operator_list[OPERATOR_COUNT])(const lld, const lld) = {add, sub, mul, divide};

int g_count;
lld g_max = LLONG_MIN;
lld g_min = LLONG_MAX;

void recursive(const lld result, const int depth)
{
    if (depth == g_count)
    {
        if (result > g_max)
        {
            g_max = result;
        }
        if (result < g_min)
        {
            g_min = result;
        }
        return;
    }
    for (int i = 0; i < OPERATOR_COUNT; i++)
    {
        if (g_operator_count[i] > 0)
        {
            g_operator_count[i]--;
            recursive(operator_list[i](result, g_num_list[depth]), depth + 1);
            g_operator_count[i]++;
        }
    }
}

int main(void)
{
    std::cin >> g_count;
    for (int i = 0; i < g_count; i++)
    {
        std::cin >> g_num_list[i];
    }
    for (auto &item : g_operator_count)
    {
        std::cin >> item;
    }

    recursive(g_num_list[0], 1);
    std::cout << g_max << std::endl;
    std::cout << g_min << std::endl;
    return 0;
}