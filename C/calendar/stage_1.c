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

int MonthDay(int year, int i)
{   
    int ret = 0;
    int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leap_year = IsLeap(year);

    ret = month_day[i-1];

    if (leap_year)
    {
        ret = ret + 1;
    }

    return ret;
}


int TotalDay(int year, int month, int day)
{
    int sum = 0;
    int i = 0;

    for ( i = 1; i < month; i++)
    {
        sum = sum + MonthDay(year, i);
    }

    sum = sum + day;

    return sum;
}


int main()
{

    int year, month, day;

    printf("Please enter the date in year/month/day:\n");
    scanf("%d", &year);
    scanf("%d", &month);
    scanf("%d", &day);
    printf("%d %d %d\n", year, month, day);

    if (month > 12 || month < 1)
    {
        printf("Invalid month\n");
        return -1;
    }

    if (day > 31 || day <1 )
    {
        printf("Invalid day\n");
        return -1;
    }

    int total_day = TotalDay(year, month, day);

    printf("%d-%d-%d is the %d th day of year %d\n", year, month, day, total_day, year);

    return 0;
}