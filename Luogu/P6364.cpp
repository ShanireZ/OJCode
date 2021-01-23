#include <cstdio>
#include <algorithm>
using namespace std;
long long read();
long long a[1000005], c[1000005];
int main()
{
    int n = read();
    long long tot = 0, cnt = 0;
    a[0] = a[n + 1] = -1;
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        if (a[i] > a[i - 1])
        {
            cnt++;
        }
        else if (a[i] < a[i - 1])
        {
            cnt = 1;
        }
        c[i] = cnt;
    }
    cnt = 0;
    for (int i = n; i >= 1; i--)
    {
        if (a[i] > a[i + 1])
        {
            cnt++;
        }
        else if (a[i] < a[i + 1])
        {
            cnt = 1;
        }
        c[i] = max(c[i], cnt);
        tot += c[i];
    }
    printf("%lld", tot);
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