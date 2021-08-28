#include <iostream>

using namespace std;

int N, M;

void recursive(int num, int count)
{
    if (count == 0)
    {
        cout << '\n';
        return;
    }
    for (size_t i = 1; i <= N; i++)
    {
        if (i != num)
        {
            recursive(i, count - 1);
        }
    }
}

int main(void)
{
    cin >> N >> M;
    for (size_t i = 1; i <= N; i++)
    {
        recursive(i, M);
    }
    return 0;
}

/*
scanf("%d %d",&a, &b);
printf("1\n2\n3\n");
*/