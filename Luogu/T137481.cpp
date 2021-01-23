#include <cstdio>
#include <algorithm>
using namespace std;
long long read(); //快读
int main()
{
    long long maxx = 0, tot1 = 0, tot2 = 0, n = read();
    for (int i = 1; i <= n; i++)
    {
        long long h1 = read();
        h1 = (i % 2) ? h1 : -h1;
        long long h2 = -h1;
        tot1 += h1, tot2 += h2;
        maxx = max(maxx, max(tot1, tot2));
        tot1 = max(tot1, 0ll), tot2 = max(tot2, 0ll);
    }
    printf("%lld", maxx);
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