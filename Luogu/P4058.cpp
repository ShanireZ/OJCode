#include <cmath>
#include <iostream>
using namespace std;
#define MX 200005
struct Tree
{
    long long h, a, t;
};
Tree ts[MX];
long long read();
int main()
{
    long long n = read(), S = read(), L = read();
    for (int i = 1; i <= n; i++)
    {
        ts[i].h = read();
    }
    for (int i = 1; i <= n; i++)
    {
        ts[i].a = read();
    }
    long long l = 0, r = 1e18;
    while (l <= r)
    {
        __int128_t mid = (l + r) / 2, tot = 0;
        for (int i = 1; i <= n; i++)
        {
            if (L <= mid * ts[i].a + ts[i].h)
            {
                tot += ts[i].h + ts[i].a * mid;
            }
        }
        (tot >= S) ? r = mid - 1 : l = mid + 1;
    }
    printf("%lld\n", l);
    return 0;
}
long long read()
{
    long long ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
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
// TAG: 卡double精度 二分答案