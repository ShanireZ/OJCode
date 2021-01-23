#include <cstdio>
#include <algorithm>
#include <iomanip>
using namespace std;
int read();
int main()
{
    int n = read(), maxs = 0, mins = 0x3f3f3f3f;
    double tot = 0;
    for (int i = 1; i <= n; i++)
    {
        int s = read();
        tot += s;
        maxs = max(maxs, s);
        mins = min(mins, s);
        if (i < 3)
        {
            continue;
        }
        printf("%.2lf\n", (tot - maxs - mins) / (i - 2));
    }
    return 0;
}
int read() //快读
{
    char ch = getchar();
    while ((ch > '9' || ch < '0') && ch != '-')
    {
        ch = getchar();
    }
    int t = 1, n = 0;
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