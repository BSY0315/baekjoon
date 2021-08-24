/* https://www.acmicpc.net/problem/1931 */
/* 11047 - 회의실 배정 */
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

typedef unsigned int uint;

int meeting_count;
pair<uint, uint> meeting_time[100000];

bool compare(const pair<uint, uint> &a, const pair<uint, uint> &b)
{
    return a.second < b.second;
}

bool find_fast_end_meeting(uint &now_time)
{
    for (int i = 0; i < meeting_count; i++)
    {
        if (meeting_time[i].first >= now_time)
        {
            now_time = meeting_time[i].second;
            return true;
        }
    }
    return false;
}

int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> meeting_count;
    for (int i = 0; i < meeting_count; i++)
    {
        cin >> meeting_time[i].first;
        cin >> meeting_time[i].second;
    }
    sort(meeting_time, meeting_time + meeting_count, compare);

    int max_meeting_count = 0;
    uint now_time = 0;
    while (find_fast_end_meeting(now_time))
    {
        max_meeting_count++;
    }
    cout << max_meeting_count;
    return 0;
}