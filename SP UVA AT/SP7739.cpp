#include <cstring>
#include <iostream>
using namespace std;
#define MX 1000005
int tmx[MX], tmn[MX], a[MX], n, m, c, ok;
int lowbit(int x)
{
    return x & -x;
}
void edit(int pos, int v)
{
    while (pos <= n)
    {
        tmx[pos] = max(tmx[pos], v), tmn[pos] = min(tmn[pos], v);
        pos += lowbit(pos);
    }
}
int query(int l, int r)
{
    int mx = -1, mn = 0x3f3f3f3f;
    while (l <= r)
    {
        if (r - lowbit(r) >= l)
        {
            mx = max(mx, tmx[r]), mn = min(mn, tmn[r]);
            r -= lowbit(r);
        }
        else
        {
            mx = max(mx, a[r]), mn = min(mn, a[r]);
            r--;
        }
    }
    return (mx - mn <= c) ? 1 : 0;
}
int main()
{
    memset(tmn, 0x3f, sizeof(tmn));
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        edit(i, a[i]);
    }
    for (int i = 1; i <= n - m + 1; i++)
    {
        if (query(i, i + m - 1))
        {
            cout << i << endl;
            ok = 1;
        }
    }
    if (ok == 0)
    {
        cout << "NONE" << endl;
    }
    return 0;
}