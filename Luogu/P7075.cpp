#include <cstdio>
using namespace std;
int d[2][15] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},  //平年
                {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}}; //閏年
//起始日 公元前 4713 年 1 月 1 日
//公元前共1721424天 完畢後到達1年1月1日
//1年1月1日-1582 年 10 月 4 日 577737天 執行完畢後到達1582年10月15日
long long read();                  //快讀
int checkr(int tp, long long year) //閏年判斷
{
    if (tp == 1) //公元前
    {
        return (year % 4 == 1) ? 1 : 0;
    }
    else if (tp == 2) //格裡高利前
    {
        return (year % 4 == 0) ? 1 : 0;
    }
    else //格裡高利後
    {
        return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 1 : 0;
    }
}
void makeans(int tp, long long &year, long long &month, long long &day)
{
    int isr = checkr(tp, year);
    while (day > d[isr][month])
    {
        day -= d[isr][month];
        month++;
        if (month > 12)
        {
            month = 1;
            tp != 1 ? year++ : year--;
            isr = checkr(tp, year);
        }
    }
}
int main()
{
    long long q = read();
    for (int i = 1; i <= q; i++)
    {
        long long ri = read();
        if (ri < 1721424) //公元前
        {
            long long year = 4713 - ri / 1461 * 4;
            ri = ri % 1461;
            long long month = 1, day = 1 + ri;
            makeans(1, year, month, day);
            printf("%lld %lld %lld BC\n", day, month, year);
        }
        else if (ri < 2299161) //格裡高利前
        {
            long long year = 4713 - ri / 1461 * 4;
            ri = ri % 1461;
            long long month = 1, day = 1 + ri;
            year = -year + 1;
            makeans(2, year, month, day);
            printf("%lld %lld %lld\n", day, month, year);
        }
        else //格裡高利後
        {
            ri -= 2299161;
            long long year, month, day;
            if (ri < 6287) //1600年前 不存在跨百年的問題
            {
                year = 1582 + ri / 1461 * 4;
                ri %= 1461;
                month = 10, day = 15 + ri;
            }
            else //1600年後
            {
                ri -= 6287;
                year = 1600 + ri / 146097 * 400;
                ri %= 146097;
                int t = (ri < 36525) ? 1 : 0; //是否是第一個百年 第一個百年第一年是閏年-特判
                if (ri >= 36525)              //非第一個百年內
                {
                    long long round = (ri - 36525) / 36524 + 1;
                    year += round * 100;
                    ri = (ri - 36525) % 36524;
                }
                if (ri >= 1460 + t) //第1個4年1460+t天 之後每4年1461天
                {
                    long long round = (ri - (1460 + t)) / 1461 + 1;
                    year += round * 4;
                    ri = (ri - (1460 + t)) % 1461;
                }
                month = 1, day = 1 + ri;
            }
            makeans(3, year, month, day);
            printf("%lld %lld %lld\n", day, month, year);
        }
    }
    return 0;
}
long long read() //快讀
{
    char ch = getchar();
    while ((ch > '9' || ch < '0') && ch != '-')
    {
        ch = getchar();
    }
    long long t = 1, n = 0;
    if (ch == '-')
    {
        t = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        n = n * 10 + ch - '0';
        ch = getchar();
    }
    return n * t;
}