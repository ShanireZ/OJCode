#include <cstdio>
using namespace std;
long long read()
{
    long long ans = 0, t = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
        {
            t = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * t;
}
int main()
{
    long long n = read(), ans = read();
    for (int i = 2; i <= n; i++)
    {
        long long x = read();
        if (x >= 0)
        {
            ans += x;
        }
        else
        {
            ans -= x;
        }
    }
    printf("%lld\n", ans);
    return 0;
}