/* https://www.acmicpc.net/problem/13305 */
/* 13305 - 주유소 */
#include <stdio.h>
#include <stdlib.h>

typedef long long int lld;

int main(void)
{
    int station_count;
    scanf("%d", &station_count);

    lld *distance_for_station = calloc(station_count - 1, sizeof(lld));
    for (int i = 0; i < station_count - 1; i++)
    {
        scanf("%d", &distance_for_station[i]);
    }
    lld *fee_for_station = calloc(station_count, sizeof(lld));
    for (int i = 0; i < station_count; i++)
    {
        scanf("%d", &fee_for_station[i]);
    }

    int min_fee_station = 0;
    lld min_cost = 0;
    for (int i = 1; i < station_count; i++)
    {
        min_cost += fee_for_station[min_fee_station] * distance_for_station[i - 1];
        if (fee_for_station[i] < fee_for_station[min_fee_station])
        {
            min_fee_station = i;
        }
    }

    printf("%lld", min_cost);
    free(distance_for_station);
    free(fee_for_station);
    return 0;
}