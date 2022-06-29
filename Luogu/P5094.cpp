#include <iostream>
#include <algorithm>
using namespace std;
struct Node
{
    long long v, x;
};
Node ns[20005];
long long n, ttot[20005], tcnt[20005], maxx;
long long read();
bool cmp(Node a, Node b)
{
    return a.v < b.v;
}
long long lowbit(long long x)
{
    return x & -x;
}
void edit(int x, long long k)
{
    while (x <= maxx)
    {
        ttot[x] += k;
        tcnt[x]++;
        x += lowbit(x);
    }
}
long long querytot(int x)
{
    long long ans = 0;
    while (x)
    {
        ans += ttot[x];
        x -= lowbit(x);
    }
    return ans;
}
long long querycnt(int x)
{
    long long ans = 0;
    while (x)
    {
        ans += tcnt[x];
        x -= lowbit(x);
    }
    return ans;
}
int main()
{
    long long ans = 0;
    n = read();
    for (int i = 1; i <= n; i++)
    {
        ns[i].v = read();
        ns[i].x = read();
        maxx = max(maxx, ns[i].x);
    }
    sort(ns + 1, ns + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        edit(ns[i].x, ns[i].x);
        long long tot = querytot(maxx) - querytot(ns[i].x);
        long long cnt = i - querycnt(ns[i].x);
        ans += ns[i].v * (tot - ns[i].x * cnt);
        tot = querytot(ns[i].x - 1);
        cnt = querycnt(ns[i].x - 1);
        ans += ns[i].v * (ns[i].x * cnt - tot);
    }
    printf("%lld\n", ans);
    return 0;
}
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