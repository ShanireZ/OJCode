#include <cstdio>
using namespace std;
inline long long read()
{
    long long ans = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}
long long h[1000005];
int main()
{
    int n = read();
    long long maxh = -1, minh = 1e18 + 5;
    for (register int i = 1; i <= n; i++)
    {
        h[i] = read();
        if (h[i] > maxh)
        {
            maxh = h[i];
        }
        if (h[i] < minh)
        {
            minh = h[i];
        }
    }
    for (register int i = 1; i <= n; i++)
    {
        printf("%lld ", maxh - h[i]);
    }
    printf("\n");
    for (register int i = 1; i <= n; i++)
    {
        printf("%lld ", h[i] - minh);
    }
    return 0;
}