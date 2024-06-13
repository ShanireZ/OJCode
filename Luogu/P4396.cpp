#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define MX 100005
struct Node
{
    int l, r, a, b, id;
};
Node ns[MX];
int n, m, a[MX], g[MX], t[MX], ans[MX][2], cg[325], cz[325]; // cg cz按值域分块,分别记录个数和种类数
bool cmp(Node x, Node y)
{
    return g[x.l] == g[y.l] ? x.r < y.r : x.l < y.l;
}
int main()
{
    cin >> n >> m;
    int sz = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        g[i] = (i - 1) / sz + 1;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> ns[i].l >> ns[i].r >> ns[i].a >> ns[i].b;
        ns[i].id = i;
    }
    sort(ns + 1, ns + m + 1, cmp);
    int st = 1, ed = 0;
    for (int i = 1; i <= m; i++)
    {
        while (ed < ns[i].r)
        {
            ed++;
            int num = a[ed];
            t[num]++;
            cg[g[num]]++, cz[g[num]] += (t[num] == 1);
        }
        while (ed > ns[i].r)
        {
            int num = a[ed];
            t[num]--;
            cg[g[num]]--, cz[g[num]] -= (t[num] == 0);
            ed--;
        }
        while (st < ns[i].l)
        {
            int num = a[st];
            t[num]--;
            cg[g[num]]--, cz[g[num]] -= (t[num] == 0);
            st++;
        }
        while (st > ns[i].l)
        {
            st--;
            int num = a[st];
            t[num]++;
            cg[g[num]]++, cz[g[num]] += (t[num] == 1);
        }
        if (g[ns[i].a] == g[ns[i].b]) // 块内暴力
        {
            for (int j = ns[i].a; j <= ns[i].b; j++)
            {
                ans[ns[i].id][0] += t[j];
                ans[ns[i].id][1] += (t[j] > 0);
            }
            continue;
        }
        for (int j = ns[i].a; j <= g[ns[i].a] * sz; j++) // 开头块
        {
            ans[ns[i].id][0] += t[j];
            ans[ns[i].id][1] += (t[j] > 0);
        }
        for (int j = g[ns[i].a] + 1; j < g[ns[i].b]; j++) // 中间整块
        {
            ans[ns[i].id][0] += cg[j];
            ans[ns[i].id][1] += cz[j];
        }
        for (int j = ns[i].b; j > (g[ns[i].b] - 1) * sz; j--) // 结尾块
        {
            ans[ns[i].id][0] += t[j];
            ans[ns[i].id][1] += (t[j] > 0);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    return 0;
}
// TAG: 莫队 值域分块 根号分治