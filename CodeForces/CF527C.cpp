#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int lc, rc, v, lv, rv;
};
Node sp[2000005], sz[2000005];
int n, w, h, rsp, rsz, pos;
void updatesp(int now, int l, int r)
{
    int mid = (l + r) / 2;
    sp[now].lv = sp[sp[now].lc].lv + (sp[sp[now].lc].lv == mid - l + 1) * sp[sp[now].rc].lv;
    sp[now].rv = sp[sp[now].rc].rv + (sp[sp[now].rc].rv == r - mid) * sp[sp[now].lc].rv;
    sp[now].v = max(sp[now].lv, sp[now].rv);
    sp[now].v = max(sp[now].v, sp[sp[now].lc].rv + sp[sp[now].rc].lv);
    sp[now].v = max(sp[now].v, max(sp[sp[now].lc].v, sp[sp[now].rc].v));
}
void updatesz(int now, int l, int r)
{
    int mid = (l + r) / 2;
    sz[now].lv = sz[sz[now].lc].lv + (sz[sz[now].lc].lv == mid - l + 1) * sz[sz[now].rc].lv;
    sz[now].rv = sz[sz[now].rc].rv + (sz[sz[now].rc].rv == r - mid) * sz[sz[now].lc].rv;
    sz[now].v = max(sz[now].lv, sz[now].rv);
    sz[now].v = max(sz[now].v, sz[sz[now].lc].rv + sz[sz[now].rc].lv);
    sz[now].v = max(sz[now].v, max(sz[sz[now].lc].v, sz[sz[now].rc].v));
}
void initsp(int &now, int l, int r)
{
    now = ++pos;
    if (l == r)
    {
        sp[now].v = sp[now].lv = sp[now].rv = 1;
        return;
    }
    int mid = (l + r) / 2;
    initsp(sp[now].lc, l, mid);
    initsp(sp[now].rc, mid + 1, r);
    updatesp(now, l, r);
}
void initsz(int &now, int l, int r)
{
    now = ++pos;
    if (l == r)
    {
        sz[now].v = sz[now].lv = sz[now].rv = 1;
        return;
    }
    int mid = (l + r) / 2;
    initsz(sz[now].lc, l, mid);
    initsz(sz[now].rc, mid + 1, r);
    updatesz(now, l, r);
}
void editsp(int now, int l, int r, int x)
{
    if (l == r)
    {
        sp[now].v = sp[now].lv = sp[now].rv = 0;
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        editsp(sp[now].lc, l, mid, x);
    }
    else
    {
        editsp(sp[now].rc, mid + 1, r, x);
    }
    updatesp(now, l, r);
}
void editsz(int now, int l, int r, int x)
{
    if (l == r)
    {
        sz[now].v = sz[now].lv = sz[now].rv = 0;
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        editsz(sz[now].lc, l, mid, x);
    }
    else
    {
        editsz(sz[now].rc, mid + 1, r, x);
    }
    updatesz(now, l, r);
}
int main()
{
    cin >> w >> h >> n;
    initsp(rsp, 1, w * 2 - 1);
    pos = 0;
    initsz(rsz, 1, h * 2 - 1);
    for (int i = 1; i <= n; i++)
    {
        char op;
        int x;
        cin >> op >> x;
        if (op == 'V')
        {
            editsp(rsp, 1, w * 2 - 1, x * 2);
        }
        else
        {
            editsz(rsz, 1, h * 2 - 1, x * 2);
        }
        cout << (sp[rsp].v / 2 + 1ll) * (sz[rsz].v / 2 + 1ll) << endl;
    }
    return 0;
}