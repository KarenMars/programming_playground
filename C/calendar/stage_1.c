#include <stdio.h>


int IsLeap(int year)
{

    if ( year % 4 == 0 && year % 100 != 0)
    {
        return 1;
    }
    else if ( year % 400 == 0 )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void main()
{

    int year, month, day;

    printf("Please enter the date in year/month/day:\n");
    scanf("%d", &year);
    scanf("%d", &month);
    scanf("%d", &day);
    printf("%d %d %d\n", year, month, day);

    int leap;

    leap = IsLeap(year);

    if ( 1 == leap )
    {
        printf("The year %d is leap year\n", year);
    }
    else
    {
        printf("The year %d is not leap year\n", year);
    }

    return;
}