#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#define MX 50005
#define LC ns[now].lc
#define RC ns[now].rc
struct Node
{
    int lc, rc, cnt[26], tag = -1;
};
Node ns[MX * 2];
int root, npos, ca[26], a[MX];
void update(int now)
{
    for (int i = 0; i < 26; i++)
    {
        ns[now].cnt[i] = ns[LC].cnt[i] + ns[RC].cnt[i];
    }
}
void init(int &now, int l, int r)
{
    now = ++npos;
    if (l == r)
    {
        ns[now].cnt[a[l]]++;
        return;
    }
    int mid = (l + r) / 2;
    init(LC, l, mid), init(RC, mid + 1, r);
    update(now);
}
void pushdown(int now, int l, int r)
{
    if (ns[now].tag != -1)
    {
        for (int i = 0; i < 26; i++)
        {
            ns[LC].cnt[i] = ns[RC].cnt[i] = 0;
        }
        int mid = (l + r) / 2;
        ns[LC].cnt[ns[now].tag] = mid - l + 1, ns[RC].cnt[ns[now].tag] = r - mid;
        ns[LC].tag = ns[RC].tag = ns[now].tag;
        ns[now].tag = -1;
    }
}
int query(int now, int l, int r, int x, int y, int k)
{
    if (x <= l && r <= y)
    {
        return ns[now].cnt[k];
    }
    pushdown(now, l, r);
    int mid = (l + r) / 2, ans = 0;
    if (x <= mid)
    {
        ans += query(LC, l, mid, x, y, k);
    }
    if (y > mid)
    {
        ans += query(RC, mid + 1, r, x, y, k);
    }
    return ans;
}
void edit(int now, int l, int r, int x, int y, int k)
{
    if (x <= l && y >= r)
    {
        for (int i = 0; i < 26; i++)
        {
            ns[now].cnt[i] = 0;
        }
        ns[now].cnt[k] = r - l + 1, ns[now].tag = k;
        return;
    }
    pushdown(now, l, r);
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        edit(LC, l, mid, x, y, k);
    }
    if (y > mid)
    {
        edit(RC, mid + 1, r, x, y, k);
    }
    update(now);
}
void countAll(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        for (int i = 0; i < 26; i++)
        {
            ca[i] += ns[now].cnt[i];
        }
        return;
    }
    pushdown(now, l, r);
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        countAll(LC, l, mid, x, y);
    }
    if (y > mid)
    {
        countAll(RC, mid + 1, r, x, y);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        a[i] = ch - 'A' - 32 * (ch >= 'a');
    }
    init(root, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int opt, x, y;
        cin >> opt >> x >> y;
        char ch;
        if (opt == 1)
        {
            cin >> ch;
            int k = ch - 'A' - 32 * (ch >= 'a');
            cout << query(root, 1, n, x, y, k) << endl;
        }
        else if (opt == 2)
        {
            cin >> ch;
            int k = ch - 'A' - 32 * (ch >= 'a');
            edit(root, 1, n, x, y, k);
        }
        else
        {
            memset(ca, 0, sizeof(ca));
            countAll(root, 1, n, x, y);
            for (int i = 0; i < 26; i++)
            {
                if (ca[i])
                {
                    edit(root, 1, n, x, x + ca[i] - 1, i);
                    x += ca[i];
                }
            }
        }
    }
    return 0;
}
// TAG: 线段树 区间修改 区间查询