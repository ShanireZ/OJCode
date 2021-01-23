#include <cstdio>
using namespace std;
int read();
int main()
{
    int n = read(), ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = i, tot = 0, trig = 1;
        while (x)
        {
            tot += x % 10;
            x /= 10;
            if (tot > 9)
            {
                break;
            }
        }
        if (tot == 9)
        {
            ans++;
        }
    }
    printf("%d", ans);
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