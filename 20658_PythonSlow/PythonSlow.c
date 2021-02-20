/* https://www.acmicpc.net/problem/20658
20648번 - 파이썬은 너무 느려 */
#include <stdio.h>
#include <stdlib.h>

#define character_to_integer(CHAR) (CHAR - '0')

int main(void)
{
    int length;
    scanf("%d", &length);
    char *string = malloc(sizeof(char) * (length + 1));
    size_t *answerList = malloc(sizeof(size_t) * (length + 1));
    scanf("%s", string);

    answerList[0] = character_to_integer(string[0]);
    for (int i = 1; i < length; i++)
    {
        if (string[i] != '-')
        {
            answerList[i] = answerList[i - 1] * 10 +
                            character_to_integer(string[i]);
        }
        else
        {
            answerList[i] = answerList[i - 1] / 10;
        }
    }

    size_t answer = 0;
    for (int i = 0; i < length; i++)
    {
        answer += answerList[i];
    }
    printf("%d", answer);
    return 0;
}
