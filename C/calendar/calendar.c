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

int WeekDay(int y, int m, int d)
{
    if (1 == m || 2 == m)
    {
        m = m + 12;
        y = y - 1;
    }

    int ret;
    ret = (d + 2*m + 3*(m+1) / 5 + y + y / 4 - y / 100 + y / 400 + 1)%7;

    return ret;    
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

    // leap year

    int leap_year = IsLeap(year);
    if (leap_year)
    {
        printf("%d is leap year.\n", year);
    }
    else
    {
        printf("%d is not leap year.\n", year);
    }

    // total day

    int total_day = TotalDay(year, month, day);

    printf("%d-%d-%d is the %d th day of year %d\n", year, month, day, total_day, year);

    // week day

    int week_day = WeekDay(year, month, day);

    switch (week_day)
    {
        case 0:
            printf("%d-%d-%d is Sunday\n", year, month, day);
            break;
        case 1:
            printf("%d-%d-%d is Monday\n", year, month, day);
            break;
        case 2:
            printf("%d-%d-%d is Tuesday\n", year, month, day);
            break;
        case 3:
            printf("%d-%d-%d is Wednesday\n", year, month, day);
            break;
        case 4:
            printf("%d-%d-%d Thursday\n", year, month, day);
            break;
        case 5:
            printf("%d-%d-%d Friday\n", year, month, day);
            break;
        case 6:
            printf("%d-%d-%d Saturday\n", year, month, day);
            break;
    }



    return 0;
}