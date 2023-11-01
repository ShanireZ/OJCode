#include <algorithm>
#include <iostream>
using namespace std;
#define MX 100005
int days[MX], b[MX], c[MX], last[MX], pre[MX * 2], to[MX * 2], n, pos;
long long a[MX], read();
void addEdge(int u, int v)
{
    to[++pos] = v, pre[pos] = last[u], last[u] = pos;
}
void dfs(int now, int fa)
{
    for (int i = last[now]; i; i = pre[i])
    {
        int nxt = to[i];
        if (nxt != fa)
        {
            dfs(nxt, now), days[now] = min(days[now], days[nxt] - 1);
        }
    }
}
__int128 counth(int l, int r, int i)
{
    __int128 d = r - l + 1;
    if (c[i] >= 0)
    {
        return d * b[i] + d * (l + r) / 2 * c[i];
    }
    int x = (1 - b[i]) / c[i];
    if (x < l)
    {
        return d;
    }
    else if (x > r)
    {
        return d * b[i] + d * (l + r) / 2 * c[i];
    }
    d = x - l + 1;
    return r - x + d * b[i] + d * (l + x) / 2 * c[i];
}
bool check(int t)
{
    for (int i = 1; i <= n; i++)
    {
        if (counth(1, t, i) < a[i])
        {
            return false;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int L = 1, R = t;
        while (L <= R)
        {
            int mid = (L + R) / 2;
            counth(mid, t, i) >= a[i] ? (L = mid + 1) : (R = mid - 1);
        }
        days[i] = R;
    }
    dfs(1, 0), sort(days + 1, days + 1 + n);
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
        check(mid) ? (R = mid - 1) : (L = mid + 1);
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
// TAG: 二分答案 树上DP