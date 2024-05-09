#include <iostream>
#include <algorithm>

inline int make_index(const char character)
{
    return character - 'a';
}

int main(int argc, const char *argv[])
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    std::vector<std::array<int, 26>> dp;
    dp.push_back({
        0,
    });

    std::string input;
    std::cin >> input;
    for (auto &&iter : input)
    {
        auto item = dp.back();
        item.at(make_index(iter))++;
        dp.push_back(item);
    }

    int count;
    std::cin >> count;

    std::vector<int> answer;
    for (int i = 0; i < count; i++)
    {
        char character;
        int start, end;
        std::cin >> character >> start >> end;
        answer.push_back(dp.at(end + 1).at(make_index(character)) -
                         dp.at(start).at(make_index(character)));
    }
    for (auto &&item : answer)
    {
        std::cout << item << '\n';
    }

    return 0;
}