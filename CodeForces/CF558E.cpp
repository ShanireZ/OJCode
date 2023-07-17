#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;
#define LC ns[now][c].lc
#define RC ns[now][c].rc
char chs[100005];
int n, m, pos, root[30];
struct Node
{
    int lc, rc, v, tag = -1; // tag:-1无需推平 0/1推平
};
Node ns[400005][30];
void update(int now, int c)
{
    ns[now][c].v = ns[LC][c].v + ns[RC][c].v;
}
void pushdown(int now, int l, int r, int c)
{
    if (ns[now][c].tag != -1)
    {
        int mid = (l + r) / 2;
        ns[LC][c].v = (mid - l + 1) * ns[now][c].tag;
        ns[RC][c].v = (r - mid) * ns[now][c].tag;
        ns[LC][c].tag = ns[RC][c].tag = ns[now][c].tag;
        ns[now][c].tag = -1;
    }
}
void init(int &now, int l, int r, int c)
{
    now = ++pos;
    if (l == r)
    {
        ns[now][c].v = (c == chs[l] - 'a');
        return;
    }
    int mid = (l + r) / 2;
    init(LC, l, mid, c), init(RC, mid + 1, r, c);
    update(now, c);
}
void edit(int now, int l, int r, int x, int y, int opt, int c)
{
    pushdown(now, l, r, c);
    if (x <= l && y >= r)
    {
        ns[now][c].v = (r - l + 1) * opt;
        ns[now][c].tag = opt;
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        edit(LC, l, mid, x, y, opt, c);
    }
    if (y > mid)
    {
        edit(RC, mid + 1, r, x, y, opt, c);
    }
    update(now, c);
}
int query(int now, int l, int r, int x, int y, int c)
{
    pushdown(now, l, r, c);
    if (x <= l && y >= r)
    {
        return ns[now][c].v;
    }
    int mid = (l + r) / 2, ans = 0;
    if (x <= mid)
    {
        ans += query(LC, l, mid, x, y, c);
    }
    if (y > mid)
    {
        ans += query(RC, mid + 1, r, x, y, c);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> chs[i];
    }
    for (int i = 0; i < 26; i++)
    {
        pos = 0;
        init(root[i], 1, n, i);
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r, k;
        cin >> l >> r >> k;
        if (k == 1) // 升序
        {
            int p = l;
            for (int j = 0; j < 26; j++)
            {
                int cnt = query(root[j], 1, n, l, r, j);
                if (cnt) // 推平
                {
                    edit(root[j], 1, n, l, r, 0, j);
                    edit(root[j], 1, n, p, p + cnt - 1, 1, j);
                    p += cnt;
                }
            }
        }
        else // 降序
        {
            int p = l;
            for (int j = 25; j >= 0; j--)
            {
                int cnt = query(root[j], 1, n, l, r, j);
                if (cnt) // 推平
                {
                    edit(root[j], 1, n, l, r, 0, j);
                    edit(root[j], 1, n, p, p + cnt - 1, 1, j);
                    p += cnt;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (query(root[j], 1, n, i, i, j))
            {
                cout << char('a' + j);
                break;
            }
        }
    }
    return 0;
}