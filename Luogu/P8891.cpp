#include <iostream>
using namespace std;
long long a[1000005], read();
int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    for (int i = 1; i <= m; i++)
    {
        int x = read();
        long long y = read();
        a[x] -= y;
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%lld ", a[i]);
    }
    return 0;
}
long long read()
{
    long long ans = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
        {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * f;
}