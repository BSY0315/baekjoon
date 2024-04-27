/**
 * https://www.acmicpc.net/problem/11054
 */

#include <iostream>
#include <array>

int main(int argc, const char *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    constexpr int MAX_SIZE = 1000;

    int sequence_size;
    std::cin >> sequence_size;

    std::array<int, MAX_SIZE> sequence;
    sequence.fill(0);
    std::array<int, MAX_SIZE> dp_increase;
    dp_increase.fill(1);
    std::array<int, MAX_SIZE> dp_decrease;
    dp_decrease.fill(1);

    for (int i = 0; i < sequence_size; i++)
    {
        std::cin >> sequence.at(i);
    }

    for (int i = 1; i < sequence_size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (sequence.at(i) > sequence.at(j) &&
                dp_increase.at(i) < dp_increase.at(j) + 1)
            {
                dp_increase.at(i) = dp_increase.at(j) + 1;
            }
        }
    }

    for (int i = sequence_size - 2; i >= 0; i--)
    {
        for (int j = sequence_size - 1; j > i; j--)
        {
            if (sequence.at(i) > sequence.at(j) &&
                dp_decrease.at(i) < dp_decrease.at(j) + 1)
            {
                dp_decrease.at(i) = dp_decrease.at(j) + 1;
            }
        }
    }

    int max = -1;
    for (int i = 0; i < sequence_size; i++)
    {
        int sum = dp_decrease.at(i) + dp_increase.at(i) - 1;
        if (sum > max)
        {
            max = sum;
        }
    }
    std::cout << max;
    return 0;
}

// 1 2 4 1 3
// 3에서는 2에서 만들어지는 수열 길이보다 더 길어야 택해짐.