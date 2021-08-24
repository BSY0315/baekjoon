/*  https://www.acmicpc.net/problem/18870 */
/* 18870 - 좌표 압축 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(void)
{
    int count;
    cin >> count;
    vector<long long int> coordinate;
    vector<long long int> lower_bound_list;
    for (int i = 0; i < count; i++)
    {
        long long int value;
        cin >> value;
        coordinate.push_back(value);
        lower_bound_list.push_back(value);
    }
    sort(lower_bound_list.begin(), lower_bound_list.end());
    lower_bound_list.erase(unique(lower_bound_list.begin(),
                                  lower_bound_list.end()),
                           lower_bound_list.end());

    for (auto &item : coordinate)
    {
        cout << lower_bound(lower_bound_list.begin(),
                            lower_bound_list.end(),
                            item) -
                    lower_bound_list.begin()
             << ' ';
    }

    return 0;
}