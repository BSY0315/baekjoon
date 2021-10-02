/* https://www.acmicpc.net/problem/1932 */
/* 1932번 - 정수 삼각형*/

#include <iostream>
#include <array>

#define left(INDEX) (INDEX)
#define right(INDEX) (INDEX + 1)

inline const int max(const int a, const int b)
{
    return a > b ? a : b;
}

constexpr int MAX_SIZE = 500;

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int size;
    std::array<std::array<int, MAX_SIZE>, MAX_SIZE> dp;

    std::cin >> size;
    for (auto &&item : dp)
    {
        item.fill(0);
    }

    int max_result = -1;
    try
    {
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j <= i; j++)
            {
                int input;
                std::cin >> input;

                int &value = dp.at(i).at(j);
                value += input;
                if (i != size - 1)
                {
                    int &left = dp.at(i + 1).at(left(j));
                    left = max(left, value);
                    dp.at(i + 1).at(right(j)) = value;
                }
                else
                {
                    max_result = max(value, max_result);
                }
            }
        }
    }
    catch (const std::out_of_range &exc)
    {
        std::cout << "error:" << exc.what();
    }
    std::cout << max_result;

    return 0;
}