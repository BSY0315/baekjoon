/* https://www.acmicpc.net/problem/14889 */
/* 14889번 - 스타트와 링크*/
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

#define MAX_N 20
#define min(X, Y) ((X < Y) ? X : Y)

int g_ability[MAX_N][MAX_N];
int g_count;

int g_min = INT_MAX;
std::vector<bool> g_bool;

int sum_ablity(const std::vector<int> &list)
{
    int sum = 0;
    for (auto iter = list.begin(); iter != list.end(); iter++)
    {
        for (int j = 1; (iter + j) != list.end(); j++)
        {
            sum += g_ability[*iter][*(iter + j)];
            sum += g_ability[*(iter + j)][*iter];
        }
    }
    return sum;
}

int main(void)
{
    std::cin >> g_count;
    for (int i = 0; i < g_count; i++)
    {
        for (int j = 0; j < g_count; j++)
        {
            std::cin >> g_ability[i][j];
        }
    }
    for (size_t i = 0; i < g_count / 2; i++)
    {
        g_bool.push_back(false);
    }
    for (size_t i = 0; i < g_count / 2; i++)
    {
        g_bool.push_back(true);
    }

    do
    {

        std::vector<int> start_team;
        std::vector<int> link_team;
        for (int i = 0; i < g_count; i++)
        {
            if (g_bool[i])
            {
                start_team.push_back(i);
            }
            else
            {
                link_team.push_back(i);
            }
        }

        int start_ability = sum_ablity(start_team);
        int link_ability = sum_ablity(link_team);
        g_min = min(abs(start_ability - link_ability), g_min);

    } while (std::next_permutation(g_bool.begin(), g_bool.end()));

    std::cout << g_min;
    return 0;
}