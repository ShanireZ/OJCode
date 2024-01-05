#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int lc, rc, v;
};
Node ns[40000005];
struct OPT
{
    int op, l, r, k;
};
OPT opts[100005];
int n, m, sz, pos, root[100005], a[100005];
vector<int> all, q1, q2;
int lowbit(int x)
{
    return x & -x;
}
void edit(int &now, int l, int r, int x, int k)
{
    if (now == 0)
    {
        now = ++pos;
    }
    if (l == r)
    {
        ns[now].v += k;
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        edit(ns[now].lc, l, mid, x, k);
    }
    else
    {
        edit(ns[now].rc, mid + 1, r, x, k);
    }
    ns[now].v = ns[ns[now].lc].v + ns[ns[now].rc].v;
}
int query(int l, int r, int x)
{
    if (l == r)
    {
        return l;
    }
    int mid = (l + r) / 2, c1 = 0, c2 = 0;
    for (int i = 0; i < (int)q1.size(); i++)
    {
        c1 += ns[ns[q1[i]].lc].v;
    }
    for (int i = 0; i < (int)q2.size(); i++)
    {
        c2 += ns[ns[q2[i]].lc].v;
    }
    if (c1 - c2 >= x)
    {
        for (int i = 0; i < (int)q1.size(); i++)
        {
            q1[i] = ns[q1[i]].lc;
        }
        for (int i = 0; i < (int)q2.size(); i++)
        {
            q2[i] = ns[q2[i]].lc;
        }
        return query(l, mid, x);
    }
    else
    {
        for (int i = 0; i < (int)q1.size(); i++)
        {
            q1[i] = ns[q1[i]].rc;
        }
        for (int i = 0; i < (int)q2.size(); i++)
        {
            q2[i] = ns[q2[i]].rc;
        }
        return query(mid + 1, r, x - (c1 - c2));
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        all.push_back(a[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        char c;
        int l, r, k;
        cin >> c >> l >> r;
        if (c == 'Q')
        {
            cin >> k;
            opts[i] = OPT{0, l, r, k};
        }
        else
        {
            opts[i] = OPT{1, l, r, 0};
            all.push_back(r);
        }
    }
    sort(all.begin(), all.end());
    unique(all.begin(), all.end());
    sz = all.size();
    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(all.begin(), all.end(), a[i]) - all.begin() + 1;
        for (int j = i; j <= n; j += lowbit(j))
        {
            edit(root[j], 1, sz, a[i], 1);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (opts[i].op == 0) // 查询
        {
            q1.clear(), q2.clear();
            for (int j = opts[i].r; j > 0; j -= lowbit(j))
            {
                q1.push_back(root[j]);
            }
            for (int j = opts[i].l - 1; j > 0; j -= lowbit(j))
            {
                q2.push_back(root[j]);
            }
            cout << all[query(1, sz, opts[i].k) - 1] << "\n";
        }
        else // 修改
        {
            int x = opts[i].l, y = opts[i].r;
            for (int j = x; j <= n; j += lowbit(j))
            {
                edit(root[j], 1, sz, a[x], -1);
            }
            a[x] = lower_bound(all.begin(), all.end(), y) - all.begin() + 1;
            for (int j = x; j <= n; j += lowbit(j))
            {
                edit(root[j], 1, sz, a[x], 1);
            }
        }
    }
    return 0;
}
// TAG: 树状数组 动态可持久 线段树 树套树