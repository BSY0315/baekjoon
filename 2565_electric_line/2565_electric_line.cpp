/**
 * https://www.acmicpc.net/problem/2565
 */
#include <iostream>
#include <array>
#include <algorithm>

int main(int argc, const char *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int line_count;
    constexpr int MAX_COUNT = 100;
    std::array<std::pair<int, int>, MAX_COUNT> position;
    std::array<int, MAX_COUNT> dp;
    dp.fill(1);

    std::cin >> line_count;
    for (int i = 0; i < line_count; i++)
    {
        std::cin >> position.at(i).first;
        std::cin >> position.at(i).second;
    }
    std::sort(position.begin(), position.begin() + line_count);
    int max = -1;
    for (int i = 1; i < line_count; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (position.at(i).second > position.at(j).second && dp.at(i) < (dp.at(j) + 1))
            {
                dp.at(i) = dp.at(j) + 1;
                if (dp.at(i) > max)
                {
                    max = dp.at(i);
                }
            }
        }
    }
    std::cout << line_count - max;

    return 0;
}