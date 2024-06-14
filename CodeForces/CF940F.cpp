#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define MX 100005
struct Node
{
    int l, r, ver, id;
};
Node ns[MX];
struct Edit
{
    int p, v, pre;
};
Edit es[MX];
int epos, npos, ls[MX * 2], t[MX * 2], ct[MX], a[MX], g[MX], ans[MX]; // 注意t和ls数组大小
bool cmp(Node x, Node y)
{
    if (g[x.l] == g[y.l])
    {
        if (g[x.r] == g[y.r])
        {
            return x.ver < y.ver;
        }
        return x.r < y.r;
    }
    return x.l < y.l;
}
void mdf(int x, int ex)
{
    ct[t[x]]--; // 统计出现次数为t[x]的数有多少种
    t[x] += ex;
    ct[t[x]]++;
}
int read()
{
    int ans = 0;
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
int main()
{
    int n = read(), m = read();
    int sz = pow(n, 2.0 / 3.0), len = n; // 再忘带修块大小是狗
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        ls[i] = a[i], g[i] = (i - 1) / sz + 1;
    }
    for (int i = 1; i <= m; i++)
    {
        int opt = read(), x = read(), y = read();
        if (opt == 1)
        {
            ns[++npos] = Node{x, y, epos, npos};
        }
        else
        {
            es[++epos] = Edit{x, y, a[x]};
            a[x] = ls[++len] = y;
        }
    }
    sort(ns + 1, ns + npos + 1, cmp), sort(ls + 1, ls + len + 1);
    len = unique(ls + 1, ls + len + 1) - ls;
    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(ls + 1, ls + len, a[i]) - ls;
    }
    for (int i = 1; i <= epos; i++)
    {
        es[i].v = lower_bound(ls + 1, ls + len, es[i].v) - ls;
        es[i].pre = lower_bound(ls + 1, ls + len, es[i].pre) - ls;
    }
    int st = 1, ed = 0;
    for (int i = 1; i <= npos; i++)
    {
        while (epos < ns[i].ver)
        {
            epos++;
            if (es[epos].p >= st && es[epos].p <= ed)
            {
                mdf(es[epos].pre, -1), mdf(es[epos].v, 1);
            }
            a[es[epos].p] = es[epos].v;
        }
        while (epos > ns[i].ver)
        {
            if (es[epos].p >= st && es[epos].p <= ed)
            {
                mdf(es[epos].v, -1), mdf(es[epos].pre, 1);
            }
            a[es[epos].p] = es[epos].pre;
            epos--;
        }
        while (ed < ns[i].r)
        {
            ed++;
            mdf(a[ed], 1);
        }
        while (ed > ns[i].r)
        {
            mdf(a[ed], -1);
            ed--;
        }
        while (st < ns[i].l)
        {
            mdf(a[st], -1);
            st++;
        }
        while (st > ns[i].l)
        {
            st--;
            mdf(a[st], 1);
        }
        ans[ns[i].id] = 1;
        while (ct[ans[ns[i].id]] > 0)
        {
            ans[ns[i].id]++;
        }
    }
    for (int i = 1; i <= npos; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}
// TAG: 带修改莫队 分块