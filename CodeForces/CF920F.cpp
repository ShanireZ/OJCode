#include <cstdio>
#include <algorithm>
using namespace std;
long long read();
int n, m;
long long ta[300005], nums[300005], pos[300005], an[1000005];
int dfn(int x)
{
    
    if (x != pos[x])
    {
        pos[x] = dfn(pos[x]);
    }
    return pos[x];
}
int lowbit(int x)
{
    return x & -x;
}
void edit(int x, long long k)
{
    while (x <= n)
    {
        ta[x] += k;
        x += lowbit(x);
    }
}
long long query(int x)
{
    long long ans = 0;
    while (x)
    {
        ans += ta[x];
        x -= lowbit(x);
    }
    return ans;
}
int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        pos[i] = i;
        nums[i] = read();
        edit(i, nums[i]);
    }
    for (int i = 1; i <= 1000000; i++)
    {
        for (int j = i; j <= 1000000; j += i)
        {
            an[j]++;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int opt = read(), l = read(), r = read();
        if (opt == 1)
        {
            int p = dfn(l);
            while (p <= r && p > 0)
            {
                long long x = nums[p];
                edit(p, an[x] - x);
                nums[p] = an[x];
                if (nums[p] <= 2)
                {
                    pos[p] = dfn(p + 1);
                }
                p = dfn(p + 1);
            }
        }
        else
        {
            printf("%lld\n", query(r) - query(l - 1));
        }
    }
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