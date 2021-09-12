/* https://www.acmicpc.net/problem/9184 */
/* 9184번 - 신나는 함수 실행*/
#include <iostream>
#include <memory>

constexpr int MAX = 21;
constexpr int NONE = 0;

template <typename... Args>
std::string string_format(const std::string &format, Args... args)
{
    size_t size = snprintf(nullptr, 0, format.c_str(), args...) + 1;
    if (size <= 0)
    {
        throw std::runtime_error("Error during formatting.");
    }
    std::unique_ptr<char[]> buf(new char[size]);
    snprintf(buf.get(), size, format.c_str(), args...);
    return std::string(buf.get(), buf.get() + size - 1);
}

int list[MAX][MAX][MAX] = {
    NONE,
};

int w(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }
    if (a > 20 || b > 20 || c > 20)
    {
        list[20][20][20] =
            w(20, 20, 20);
        return list[20][20][20];
    }

    if (list[a][b][c] != NONE)
    {
        return list[a][b][c];
    }

    if (a < b && b < c)
    {
        list[a][b][c] =
            w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        return list[a][b][c];
    }
    else
    {
        list[a][b][c] =
            w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
        return list[a][b][c];
    }
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int a, b, c;
    while (true)
    {
        std::cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
        {
            break;
        }
        std::cout << string_format("w(%d, %d, %d) = %d", a, b, c, w(a, b, c)) << std::endl;
    }
    return 0;
}