/* https://www.acmicpc.net/problem/17298 */
/* 17028 - 오큰수  */
#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    stack<int> stk;

    int count;
    cin >> count;

    int *array = new int[count];
    int *answer = new int[count];
    for (int i = 0; i < count; i++)
    {
        cin >> array[i];
        answer[i] = -1;
    }

    stk.push(0);
    for (int index = 1; index < count; index++)
    {
        while (array[index] > array[stk.top()])
        {
            answer[stk.top()] = array[index];
            stk.pop();
            if (stk.empty())
            {
                break;
            }
        }
        stk.push(index);
    }
    for (int i = 0; i < count; i++)
    {
        cout << answer[i] << " ";
    }

    delete[] array;
    delete[] answer;
    return 0;
}
