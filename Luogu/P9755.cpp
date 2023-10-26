#include <algorithm>
#include <iostream>
using namespace std;
#define MX 100005
int days[MX], b[MX], c[MX], last[MX], pre[MX * 2], to[MX * 2], n, pos;
long long a[MX], read();
void addEdge(int u, int v)
{
    to[++pos] = v;
    pre[pos] = last[u];
    last[u] = pos;
}
void dfs(int now, int fa)
{
    for (int i = last[now]; i; i = pre[i])
    {
        int nxt = to[i];
        if (nxt != fa)
        {
            dfs(nxt, now);
            days[now] = min(days[now], days[nxt] - 1);
        }
    }
}
bool check(int t)
{
    for (int i = 1; i <= n; i++)
    {
        int L = 1, R = t;
        while (L <= R)
        {
            long long mid = (L + R) / 2, h = 0;
            if (c[i] >= 0 || (1 - b[i]) / c[i] >= t)
            {
                long long x = t - mid + 1;
                h = x * b[i] + x * (mid + t) / 2 * c[i];
            }
            else
            {
                long long d = (1 - b[i]) / c[i], x = d - mid + 1;
                h = (d < mid) ? t - mid + 1 : t - d + x * b[i] + x * (mid + d) / 2 * c[i];
            }
            h >= a[i] ? L = mid + 1 : R = mid - 1;
        }
        days[i] = R;
    }
    dfs(1, 0);
    sort(days + 1, days + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        if (days[i] < i)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read(), b[i] = read(), c[i] = read();
    }
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        addEdge(u, v), addEdge(v, u);
    }
    int L = n, R = 1e9;
    while (L <= R)
    {
        int mid = (L + R) / 2;
        check(mid) ? R = mid - 1 : L = mid + 1;
    }
    printf("%d\n", L);
    return 0;
}
long long read()
{
    long long ans = 0, t = 1;
    char ch = getchar();
    while (ch != '-' && (ch > '9' || ch < '0'))
    {
        ch = getchar();
    }
    if (ch == '-')
    {
        t = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * t;
}