/* https://www.acmicpc.net/problem/1931 */
/* 11047 - 회의실 배정 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned int uint;

int meeting_count;
vector<pair<uint, uint>> meeting_time;

bool compare(const pair<uint, uint> &a, const pair<uint, uint> &b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    else
    {
        return a.second < b.second;
    }
}

int main(void)
{
    cin >> meeting_count;
    uint start, end;
    for (int i = 0; i < meeting_count; i++)
    {
        cin >> start >> end;
        meeting_time.push_back(make_pair(start, end));
    }
    sort(meeting_time.begin(), meeting_time.end(), compare);

    int max_meeting_count = 0;
    uint now_time = 0;
    for (int i = 0; i < meeting_count; i++)
    {
        if (meeting_time[i].first >= now_time)
        {
            now_time = meeting_time[i].second;
            max_meeting_count++;
        }
    }

    cout << max_meeting_count;
    return 0;
}