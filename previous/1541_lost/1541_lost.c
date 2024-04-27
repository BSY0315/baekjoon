/* https://www.acmicpc.net/problem/1541 */
/* 1541 - 잃어버린 괄호 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int asd(char *sd)
{
    char str[6];
    int length = 0;
    for (size_t i = 0; sd[i] != '+' && sd[i] != '-' && sd[i] != '\0'; i++)
    {
        str[length++] = sd[i];
    }
    str[length] = '\0';
    atoi(str);
}

int main(void)
{
    char expression[100];
    expression[0] = '+';
    scanf("%s", expression + 1);

    int count = strlen(expression);
    bool minus = false;
    for (size_t i = 0; i < count; i++)
    {
        if (!minus)
        {
            if (expression[i] == '-')
            {
                minus = true;
            }
        }
        else
        {
            if (expression[i] == '+')
            {
                expression[i] = '-';
            }
        }
    }

    int sum = 0;

    for (size_t i = 0; i < count; i++)
    {
        if (expression[i] == '+')
        {
            sum += asd(expression + i + 1);
        }
        else if (expression[i] == '-')
        {
            sum -= asd(expression + i + 1);
        }
    }
    printf("%d", sum);
    return 0;
}