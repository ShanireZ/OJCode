#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
long long read()
{
    long long ans = 0, type = 1;
    char ch = getchar();
    while (ch != '-' && (ch > '9' || ch < '0'))
    {
        ch = getchar();
    }
    if (ch == '-')
    {
        type = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * type;
}
int n, pf, pm, pa, pos, t[100005];
long long frt[10000005], mge[10000005], tot;
long long choose()
{
    long long ans;
    if (pf != n && frt[pf] < mge[pm] || mge[pm] == 0)
    {
        ans = frt[pf++];
    }
    else
    {
        ans = mge[pm++];
    }
    return ans;
}
int main()
{
    n = read();
    for (int i = 0; i < n; i++)
    {
        t[read()]++;
    }
    for (int i = 1; i <= 100000; i++)
    {
        for (int j = 1; j <= t[i]; j++)
        {
            frt[pos++] = i;
        }
    }
    for (int i = 1; i < n; i++)
    {
        long long now = choose() + choose();
        mge[pa++] = now;
        tot += now;
    }
    printf("%lld\n", tot);
    return 0;
}