/* https://www.acmicpc.net/problem/20658
20648번 - 파이썬은 너무 느려 */
#include <stdio.h>
#include <stdlib.h>

#define character_to_integer(CHAR) ((int)CHAR - '0')
#define MAX_LENGTH (500001)

typedef long long int lld;

char string[MAX_LENGTH];
char intergerAsString[MAX_LENGTH] = {"0"};

int main(void)
{
    int length;
    scanf("%d", &length);
    scanf("%s", string);

    lld answer = 0;
    int index = 1;
    for (int i = 0; i < length; i++)
    {
        if (string[i] != '-')
        {
            intergerAsString[index] = string[i];
            intergerAsString[index + 1] = '\0';
            index++;
        }
        else
        {
            index--;
            intergerAsString[index] = '\0';
        }
        answer += atoi(intergerAsString);
    }
    printf("%lld", answer);
    return 0;
}
