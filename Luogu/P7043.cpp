#include <cstdio>
#include <algorithm>
using namespace std;
long long a[2000005];
long long read(); //快读
int main()
{
    int t = read();
    for (int i = 1; i <= t; i++)
    {
        int n = read(), maxp = 0, cmaxp = 0;
        long long m = read();
        for (int j = 1; j <= n; j++)
        {
            a[j] = read();
            if (a[maxp] < a[j])
            {
                maxp = j;
            }
        }
        for (int j = 1; j < n; j++)
        {
            int x = read(), y = read();
            if (x == maxp || y == maxp)
            {
                int id = x + y - maxp;
                if (a[id] == a[cmaxp])
                {
                    cmaxp = min(cmaxp, id);
                }
                else if (a[id] > a[cmaxp])
                {
                    cmaxp = id;
                }
            }
        }
        if (n == 1)
        {
            printf("1\n");
            continue;
        }
        if (a[maxp] - a[cmaxp] > m)
        {
            printf("%d\n", maxp);
        }
        else
        {
            m -= (a[maxp] - a[cmaxp]);
            if (m % 2 == 0)
            {
                printf("%d\n", min(maxp, cmaxp));
            }
            else
            {
                printf("%d\n", max(maxp, cmaxp));
            }
        }
    }
    return 0;
}
long long read() //快读
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