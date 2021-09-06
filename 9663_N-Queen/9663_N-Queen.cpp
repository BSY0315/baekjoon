/* https://www.acmicpc.net/problem/9663
9663번 - N-Queen*/
#include <iostream>

#define MAX (15)
#define CAN_PLACE (0)
#define PLACE_QUEEN (1)
#define REMOVE_QUEEN (-1)

#define update_state(INDEX_X, INDEX_Y) g_chess_board[INDEX_X][INDEX_Y] += state;

int g_total_occasion = 0;
int g_count;

int g_chess_board[MAX][MAX] = {
    CAN_PLACE,
};

void recursive(const int index, const int count);
inline void set_board(const int x, const int y, const int state);
inline void set_accross_board_recursive(const int x, const int y, std::pair<int, int> direction, const int state);

void recursive(const int count)
{
    if (count == g_count)
    {
        g_total_occasion++;
        return;
    }
    for (int i = 0; i < g_count; i++)
    {
        if (g_chess_board[count][i] == CAN_PLACE)
        {
            set_board(count, i, PLACE_QUEEN);
            recursive(count + 1);
            set_board(count, i, REMOVE_QUEEN);
            // 이 과정에서 겹치는 보드 부분을 없애버림
        }
    }
}

inline void set_board(const int x, const int y, const int state)
{
    for (int i = 0; i < g_count; i++)
    {
        update_state(x, i);
    }
    for (int i = 0; i < g_count; i++)
    {
        update_state(i, y);
    }
    set_accross_board_recursive(x, y, {1, 1}, state);
    set_accross_board_recursive(x, y, {-1, -1}, state);
    set_accross_board_recursive(x, y, {1, -1}, state);
    set_accross_board_recursive(x, y, {-1, 1}, state);
}

inline void set_accross_board_recursive(const int x, const int y, std::pair<int, int> direction, const int state)
{
    if (x < 0 || x >= g_count)
    {
        return;
    }
    if (y < 0 || y >= g_count)
    {
        return;
    }
    update_state(x, y);
    set_accross_board_recursive(x + direction.first, y + direction.second, direction, state);
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    std::cin >> g_count;
    recursive(0);
    std::cout << g_total_occasion;
    return 0;
}