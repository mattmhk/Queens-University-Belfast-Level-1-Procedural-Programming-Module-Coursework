#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    float average_hourly=0, average_daily=0;
    srand((unsigned int)time(NULL));
    int temperature_reading[7][24];
    
    for(int day = 0; day < 7; day++)
    {
        for(int hour = 0; hour < 24; hour++)
        {
            temperature_reading[day][hour] = rand() % 41;
            average_daily += temperature_reading[day][hour];
        }
        average_daily /= 24;
        printf("The average temperature for day %d is %.2f\n", day+1, average_daily);
        average_daily = 0;
    }

    for (int hour = 0; hour < 24; hour++)
    {
        for (int day = 0; day < 7; day++)
        {
            average_hourly += temperature_reading[day][hour];
        }
        average_hourly /= 7;
        printf("The average temperature for hour %d is %.2f\n", hour+1, average_hourly);
        average_hourly = 0;
    }
}
