/* https://www.acmicpc.net/problem/1149 */
/* 1149¹ø - RGB°Å¸® */
#include <iostream>
#include <array>
#include <climits>

constexpr int COLOR_MAX = 3;
constexpr int MAX = 1000;

constexpr int ERROR_CODE = -1;

enum COLOR
{
    RED,
    GREEN,
    BLUE
};

std::array<std::array<int, COLOR_MAX>, MAX> g_dp;
std::array<std::array<int, COLOR_MAX>, MAX> g_cost;

inline int min(const int a, const int b)
{
    return a < b ? a : b;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int result_min = INT_MAX;
    int count;
    std::cin >> count;
    try
    {
        for (int i = 0; i < count; i++)
        {
            for (auto &&item : g_cost.at(i))
            {
                std::cin >> item;
            }
        }
        g_dp.front().at(COLOR::RED) = g_cost.front().at(COLOR::RED);
        g_dp.front().at(COLOR::BLUE) = g_cost.front().at(COLOR::BLUE);
        g_dp.front().at(COLOR::GREEN) = g_cost.front().at(COLOR::GREEN);
        for (auto iter = g_dp.begin() + 1, cost = g_cost.begin() + 1; iter != g_dp.begin() + count; iter++, cost++)
        {
            iter->at(COLOR::RED) = min((iter - 1)->at(COLOR::BLUE),
                                       (iter - 1)->at(COLOR::GREEN)) +
                                   cost->at(COLOR::RED);

            iter->at(COLOR::BLUE) = min((iter - 1)->at(COLOR::RED),
                                        (iter - 1)->at(COLOR::GREEN)) +
                                    cost->at(COLOR::BLUE);

            iter->at(COLOR::GREEN) = min((iter - 1)->at(COLOR::BLUE),
                                         (iter - 1)->at(COLOR::RED)) +
                                     cost->at(COLOR::GREEN);
        }

        const auto value = g_dp.at(count - 1);
        for (const auto iter : value)
        {
            result_min = min(iter, result_min);
        }
    }
    catch (const std::out_of_range &exc)
    {
        std::cout << "error : " << exc.what() << std::endl;
        return ERROR_CODE;
    }

    std::cout << result_min;
    return 0;
}