/**
 * https://www.acmicpc.net/problem/1912
 */

#include <iostream>
#include <array>
#include <algorithm>

int main(int argc, const char *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int sequence_count;
    constexpr int MAX_COUNT = 100000;
    std::array<int, MAX_COUNT> sequence;
    std::array<int, MAX_COUNT> dp;

    std::cin >> sequence_count;
    for (int i = 0; i < sequence_count; i++)
    {
        std::cin >> sequence.at(i);
    }
    dp.at(0) = sequence.at(0);

    for (int i = 1; i < sequence_count; i++)
    {
        dp.at(i) = std::max(dp.at(i - 1) + sequence.at(i), sequence.at(i));
    }

    std::cout << *std::max_element(dp.cbegin(), dp.cbegin() + sequence_count);
    return 0;
}