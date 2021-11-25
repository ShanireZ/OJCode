#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
long long read()
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
int n, m;
struct Area
{
    long long l, r;
    bool operator<(const Area oth) const
    {
        return l < oth.l;
    }
};
Area ars[100005];
int main()
{
    n = read(), m = read();
    for (int i = 1; i <= m; i++)
    {
        ars[i].l = read(), ars[i].r = read();
    }
    sort(ars + 1, ars + 1 + m);
    long long l = 0, r = ars[m].r;
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        long long tot = 0, p = -1;
        for (int i = 1; i <= m; i++)
        {
            if (p < ars[i].l)
            {
                p = ars[i].l;
            }
            else if (p > ars[i].r)
            {
                continue;
            }
            long long x = (ars[i].r - p) / mid + 1;
            tot += x, p += x * mid;
        }
        if (tot >= n)
        {
            l = mid + 1; //mid满足 l-1=mid一定满足
        }
        else
        {
            r = mid - 1;
        }
    }
    printf("%lld\n", l - 1);
    return 0;
}