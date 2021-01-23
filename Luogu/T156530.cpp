#include <iostream>
#include <string>
using namespace std;
string m[15] = {"", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
int d[2][15] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
int main()
{
    string str;
    cin >> str;
    str.append("+++");
    int day = 0, year = 0, month = 0, p = 0;
    while (str[p] >= '0' && str[p] <= '9')
    {
        day = day * 10 + (str[p] - '0');
        p++;
    }
    string strm = str.substr(p, 3);
    for (int i = 1; i <= 12; i++)
    {
        if (strm == m[i])
        {
            month = i;
            break;
        }
    }
    p += 3;
    while (str[p] >= '0' && str[p] <= '9')
    {
        year = year * 10 + (str[p] - '0');
        p++;
    }
    int tot = 0, isr = 0;
    int syear = 1, smonth = 1, sday = 1;
    while (true)
    {
        if (syear == year && smonth == month && sday == day)
        {
            cout << tot;
            break;
        }
        tot++;
        sday++;
        if (syear == 1582 && smonth == 10 && sday == 5)
        {
            sday = 15;
        }
        if (sday > d[isr][smonth])
        {
            sday = 1;
            smonth++;
            if (smonth > 12)
            {
                smonth = 1;
                syear++;
                isr = 0;
                if (syear >= 1584)
                {
                    if (syear % 4 == 0 && syear % 100 != 0 || syear % 400 == 0)
                    {
                        isr = 1;
                    }
                }
                else
                {
                    if (syear % 4 == 0)
                    {
                        isr = 1;
                    }
                }
            }
        }
    }
    return 0;
}