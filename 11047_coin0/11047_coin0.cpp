/* https://www.acmicpc.net/problem/11047 */
/* 11047 - 동전 0 */
#include <iostream>

using namespace std;

int main(void)
{
    int coinCount;
    size_t sum;
    cin >> coinCount >> sum;

    int coinValue[10];
    for (int i = 0; i < coinCount; i++)
    {
        cin >> coinValue[i];
    }

    int neededCoinCount = 0;
    for (int i = coinCount - 1; i >= 0; i--)
    {
        if (coinValue[i] <= sum)
        {
            neededCoinCount += sum / coinValue[i];
            sum = sum % coinValue[i];
        }
    }
    cout << neededCoinCount;
    return 0;
}