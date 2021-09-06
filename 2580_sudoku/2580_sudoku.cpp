/* https://www.acmicpc.net/problem/2580*/
/* 2580 - 스도쿠 */
#include <iostream>
#include <vector>

#define LINE (9)
#define NONE (0)
#define get_square_index(X, Y) ((X / 3) * 3 + (Y / 3))

int g_sudoku_board[LINE][LINE] = {
    0,
};
bool g_is_exist_row[LINE][LINE + 1] = {
    false,
};
bool g_is_exist_column[LINE][LINE + 1] = {
    false,
};
bool g_is_exist_square[LINE][LINE + 1] = {
    false,
};

std::vector<std::pair<int, int>> g_zero_list;

void recursive(const std::vector<std::pair<int, int>>::iterator item)
{
    if (item == g_zero_list.end())
    {
        for (auto &&i : g_sudoku_board)
        {
            for (auto &&j : i)
            {
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
        exit(0);
    }
    int square_index = get_square_index(item->first, item->second);
    for (int i = 1; i <= LINE; i++)
    {
        if (!g_is_exist_square[square_index][i] &&
            !g_is_exist_row[item->first][i] &&
            !g_is_exist_column[item->second][i])
        {
            g_sudoku_board[item->first][item->second] = i;
            g_is_exist_square[square_index][i] = true;
            g_is_exist_row[item->first][i] = true;
            g_is_exist_column[item->second][i] = true;
            recursive(item + 1);
            g_sudoku_board[item->first][item->second] = NONE;
            g_is_exist_square[square_index][i] = false;
            g_is_exist_row[item->first][i] = false;
            g_is_exist_column[item->second][i] = false;
        }
    }
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    for (size_t i = 0; i < LINE; i++)
    {
        for (size_t j = 0; j < LINE; j++)
        {
            int input;
            std ::cin >> input;
            if (input == NONE)
            {
                g_zero_list.push_back({i, j});
            }
            g_sudoku_board[i][j] = input;
            g_is_exist_row[i][input] = true;
            g_is_exist_column[j][input] = true;
            g_is_exist_square[get_square_index(i, j)][input] = true;
        }
    }
    recursive(g_zero_list.begin());
    return 0;
}